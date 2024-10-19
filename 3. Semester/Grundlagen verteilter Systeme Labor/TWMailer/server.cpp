#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

void handleClient(int client_socket, const std::string &mail_spool_dir)
{
    char buffer[1024];
    std::string command;

    while (true)
    {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0)
        {
            close(client_socket);
            break;
        }

        command = std::string(buffer);
        std::stringstream ss(command);
        std::string line;
        std::getline(ss, line);

        if (line == "SEND")
        {
            std::string sender, receiver, subject, message, msg_line;

            std::getline(ss, sender);
            std::getline(ss, receiver);
            std::getline(ss, subject);

            std::ostringstream msg_stream;
            while (std::getline(ss, msg_line) && msg_line != ".")
            {
                msg_stream << msg_line << "\n";
            }
            message = msg_stream.str();

            std::string user_dir = mail_spool_dir + "/" + receiver;
            fs::create_directories(user_dir);
            int msg_count = std::distance(fs::directory_iterator(user_dir), fs::directory_iterator{});
            std::string msg_filename = user_dir + "/msg_" + std::to_string(msg_count + 1) + ".txt";

            std::ofstream msg_file(msg_filename);
            msg_file << "Sender: " << sender << "\n";
            msg_file << "Subject: " << subject << "\n";
            msg_file << "Message: \n"
                     << message << "\n";
            msg_file.close();

            std::cout << "Received message from " << sender << " for " << receiver << "\n";
            send(client_socket, "OK\n", 3, 0);
        }
        else if (line == "LIST")
        {
            std::string username;
            std::getline(ss, username);

            std::string user_dir = mail_spool_dir + "/" + username;

            // Überprüfe, ob das Verzeichnis für den Benutzer existiert
            if (!fs::exists(user_dir))
            {
                // Wenn der Benutzer nicht existiert, wird genauso wie bei keinen Nachrichten geantwortet
                send(client_socket, "0\n", 3, 0); // Schicke "0\n" falls keine Nachrichten existieren
                std::cout << "Sent 0 messages to client\n";
                send(client_socket, "OK\n", 3, 0); // Sende OK als Abschluss
                std::cout << "User " << username << " not found. Sent 0 messages.\n";
            }
            else
            {
                int msg_count = 0;
                std::ostringstream response;

                // Durchsuche das Benutzerverzeichnis nach Nachrichten
                for (const auto &entry : fs::directory_iterator(user_dir))
                {
                    std::ifstream msg_file(entry.path());
                    std::string sender, subject;

                    // Lies die "Sender:" Zeile und die "Subject:" Zeile
                    std::getline(msg_file, sender);  // Überspringe die Sender-Zeile
                    std::getline(msg_file, subject); // Lies die Subject-Zeile

                    // Überprüfe, ob es wirklich eine "Subject:" Zeile ist
                    if (subject.find("Subject: ") == 0)
                    {
                        response << subject.substr(9) << "\n"; // Entferne "Subject: " und sende nur den Betreff
                    }

                    msg_count++;
                }

                // Sende die Anzahl der Nachrichten mit einem abschließenden \n
                std::ostringstream header;
                header << msg_count << "\n";
                send(client_socket, header.str().c_str(), header.str().size(), 0); // Senden der Anzahl der Nachrichten

                // Sende die Betreffzeilen
                send(client_socket, response.str().c_str(), response.str().size(), 0); // Senden der Betreffzeilen

                // Sende OK als Abschluss
                std::cout << "Sent " << msg_count << " messages to client\n";
                send(client_socket, "OK\n", 3, 0); // Bestätigung, dass alles gesendet wurde
            }
        }
        else if (line == "READ")
        {
            std::string username;
            int message_number;
            ss >> username >> message_number;

            std::string msg_filename = mail_spool_dir + "/" + username + "/msg_" + std::to_string(message_number) + ".txt";
            if (fs::exists(msg_filename))
            {
                std::ifstream msg_file(msg_filename);
                std::ostringstream response;
                response << "OK\n"
                         << msg_file.rdbuf();
                std::cout << "Sent message to client\n";
                send(client_socket, response.str().c_str(), response.str().size(), 0);
            }
            else
            {
                send(client_socket, "ERR\n", 4, 0);
            }
        }
        else if (line == "DEL")
        {
            std::string username;
            int message_number;
            ss >> username >> message_number;

            std::string msg_filename = mail_spool_dir + "/" + username + "/msg_" + std::to_string(message_number) + ".txt";
            if (fs::exists(msg_filename))
            {
                fs::remove(msg_filename);
                std::cout << "Deleted message " << message_number << " for " << username << "\n";
                send(client_socket, "OK\n", 3, 0);
            }
            else
            {
                send(client_socket, "ERR\n", 4, 0);
            }
        }
        else if (line == "QUIT")
        {
            std::cout << "Client disconnected\n";
            close(client_socket);
            break;
        }
        else
        {
            send(client_socket, "ERR\n", 4, 0);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: ./twmailer-server <port> <mail-spool-directory>\n";
        return 1;
    }

    int port = std::stoi(argv[1]);
    std::string mail_spool_dir = argv[2];

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1)
    {
        std::cerr << "Failed to create socket\n";
        return 1;
    }

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        std::cerr << "Failed to bind socket\n";
        return 1;
    }

    if (listen(server_socket, 10) == -1)
    {
        std::cerr << "Failed to listen on socket\n";
        return 1;
    }

    std::cout << "Server listening on port " << port << "\n";

    while (true)
    {
        int client_socket = accept(server_socket, nullptr, nullptr);
        if (client_socket == -1)
        {
            std::cerr << "Failed to accept connection\n";
            continue;
        }
        handleClient(client_socket, mail_spool_dir);
    }

    close(server_socket);
    return 0;
}
