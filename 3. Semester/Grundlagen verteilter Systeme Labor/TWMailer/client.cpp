#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sstream> // Für ostringstream

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: ./twmailer-client <ip> <port>\n";
        return 1;
    }

    const char *ip = argv[1];
    int port = std::stoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        std::cerr << "Failed to create socket\n";
        return 1;
    }

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0)
    {
        std::cerr << "Invalid IP address\n";
        return 1;
    }

    if (connect(sock, (sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        std::cerr << "Connection failed\n";
        return 1;
    }

    std::string command;
    char buffer[1024];

    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, command);

        if (command == "SEND")
        {
            std::string sender, receiver, subject, message, line;

            // Sender
            std::cout << "Enter Sender: ";
            std::getline(std::cin, sender);

            // Receiver
            std::cout << "Enter Receiver: ";
            std::getline(std::cin, receiver);

            // Subject
            std::cout << "Enter Subject (max 80 chars): ";
            std::getline(std::cin, subject);

            // Message
            std::cout << "Enter Message (end with a dot '.' on a new line):\n";
            std::ostringstream message_stream;
            while (std::getline(std::cin, line) && line != ".")
            {
                message_stream << line << "\n";
            }
            message = message_stream.str();

            // Senden des SEND-Kommandos mit den Eingaben des Benutzers
            std::ostringstream send_command;
            send_command << "SEND\n"
                         << sender << "\n"
                         << receiver << "\n"
                         << subject << "\n"
                         << message << ".\n";
            send(sock, send_command.str().c_str(), send_command.str().size(), 0);
        }
        else if (command == "LIST")
        {
            // LIST command handling
            std::string username;
            std::cout << "Enter Username: ";
            std::getline(std::cin, username);

            // Senden des LIST-Befehls mit dem Benutzernamen
            std::ostringstream list_command;
            list_command << "LIST\n"
                         << username << "\n";
            send(sock, list_command.str().c_str(), list_command.str().size(), 0);

            // Empfang der Serverantwort und Ausgabe der Subjects
            memset(buffer, 0, sizeof(buffer));
            int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
            if (bytes_received > 0)
            {
                std::cout << "Messages for user '" << username << "':\n";
                std::istringstream response(buffer);
                std::string line;
                int message_count;

                // Lesen der Anzahl der Nachrichten
                response >> message_count;
                std::getline(response, line); // Um das neue Zeilenzeichen nach der Zahl zu verarbeiten

                // Falls keine Nachrichten vorhanden sind
                if (message_count == 0)
                {
                    std::cout << "No messages.\n";
                }
                else
                {
                    // Ausgabe der Betreffzeilen
                    for (int i = 0; i < message_count; ++i)
                    {
                        std::getline(response, line);
                        std::cout << "Message " << (i + 1) << ": " << line << "\n";
                    }
                }
            }
        }
        else if (command == "READ")
        {
            // READ command handling
            std::string username;
            int message_number;
            std::cout << "Enter Username: ";
            std::getline(std::cin, username);
            std::cout << "Enter Message Number: ";
            std::cin >> message_number;
            std::cin.ignore(); // Um das '\n' nach der Eingabe zu ignorieren

            // Senden des READ-Befehls mit Benutzername und Nachrichten-Nummer
            std::ostringstream read_command;
            read_command << "READ\n"
                         << username << "\n"
                         << message_number << "\n";
            send(sock, read_command.str().c_str(), read_command.str().size(), 0);
        }
        else if (command == "DEL")
        {
            // DEL command handling
            std::string username;
            int message_number;
            std::cout << "Enter Username: ";
            std::getline(std::cin, username);
            std::cout << "Enter Message Number: ";
            std::cin >> message_number;
            std::cin.ignore(); // Um das '\n' nach der Eingabe zu ignorieren

            // Senden des DEL-Befehls mit Benutzername und Nachrichten-Nummer
            std::ostringstream del_command;
            del_command << "DEL\n"
                        << username << "\n"
                        << message_number << "\n";
            send(sock, del_command.str().c_str(), del_command.str().size(), 0);
        }
        else
        {
            command += "\n";
            send(sock, command.c_str(), command.size(), 0);
        }

        if (command.find("QUIT") != std::string::npos)
        {
            break;
        }

        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received > 0)
        {
            std::cout << buffer;
        }
    }

    close(sock);
    return 0;
}
