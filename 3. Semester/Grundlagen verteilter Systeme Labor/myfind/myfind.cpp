#include <iostream>
#include <vector>
#include <string>
#include <filesystem> // C++17 filesystem library
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <fcntl.h> // For O_CREAT and O_WRONLY
#include <sys/types.h>
#include <sys/stat.h>

using namespace std;
namespace fs = std::filesystem;


void searchFile(const string& searchpath, const string& filename, bool recursive, bool caseInsensitive, int fd) {
    // Redirect stdout to the provided file descriptor
    dup2(fd, STDOUT_FILENO);
    close(fd);

    if (recursive) {
        // Recursive directory iteration
        for (const auto& entry : fs::recursive_directory_iterator(searchpath)) {
            if (fs::is_regular_file(entry.status())) { // Check if the entry is a regular file
                string entryFilename = entry.path().filename().string();
                if (caseInsensitive) {
                    transform(entryFilename.begin(), entryFilename.end(), entryFilename.begin(), ::tolower);
                    string lowerFilename = filename;
                    transform(lowerFilename.begin(), lowerFilename.end(), lowerFilename.begin(), ::tolower);
                    if (entryFilename == lowerFilename) {
                        cout << getpid() << ": " << filename << ": " << fs::absolute(entry.path()) << endl;
                    }
                } else {
                    if (entryFilename == filename) {
                        cout << getpid() << ": " << filename << ": " << fs::absolute(entry.path()) << endl;
                    }
                }
            }
        }
    } else {
        // Non-recursive directory iteration
        for (const auto& entry : fs::directory_iterator(searchpath)) {
            if (fs::is_regular_file(entry.status())) { // Check if the entry is a regular file
                string entryFilename = entry.path().filename().string();
                if (caseInsensitive) {
                    transform(entryFilename.begin(), entryFilename.end(), entryFilename.begin(), ::tolower);
                    string lowerFilename = filename;
                    transform(lowerFilename.begin(), lowerFilename.end(), lowerFilename.begin(), ::tolower);
                    if (entryFilename == lowerFilename) {
                        cout << getpid() << ": " << filename << ": " << fs::absolute(entry.path()) << endl; // Print absolute path
                    }
                } else {
                    if (entryFilename == filename) {
                        cout << getpid() << ": " << filename << ": " << fs::absolute(entry.path()) << endl; // Print absolute path
                    }
                }
            }
        }
    }
}

/**
 * The main program accepts command-line arguments for search options, search path, and filenames.
 * It parses the arguments using getopt() to handle the -R (recursive) and -i (case-insensitive) options.
 * For each filename provided, the program fork()s a child process.
 * Each child process calls the searchFile() function to search for its respective filename in the specified search path.
 * If a file is found, the child process prints the result in the format:
 * <pid>: <filename>: <complete-path-to-found-file>
 * The parent process waits for all child processes to terminate using waitpid() to prevent zombie processes.
 * The output of each child process is redirected to a temporary file to ensure synchronized output.
 * The parent process reads these files sequentially and prints their contents to stdout.
 */
int main(int argc, char* argv[]) {
    bool recursive = false;
    bool caseInsensitive = false;
    string searchpath;
    vector<string> filenames;

    // Use getopt() to parse command-line options
    int opt;
    while ((opt = getopt(argc, argv, "Ri")) != -1) {
        switch (opt) {
            case 'R':
                recursive = true;
                break;
            case 'i':
                caseInsensitive = true;
                break;
            default:
                cerr << "Usage: " << argv[0] << " [-R] [-i] searchpath filename1 [filename2] ... [filenameN]" << endl;
                return EXIT_FAILURE;
        }
    }

    // Get the search path
    if (optind < argc) {
        searchpath = argv[optind++];
    } else {
        cerr << "Usage: " << argv[0] << " [-R] [-i] searchpath filename1 [filename2] ... [filenameN]" << endl;
        return EXIT_FAILURE;
    }

    // Get the filenames to search for
    while (optind < argc) {
        filenames.push_back(argv[optind++]);
    }

    vector<pid_t> childPids;
    vector<string> tempFiles;

    for (const auto& filename : filenames) {
        // Create a temporary file for each child process
        string tempFile = "/tmp/myfind_" + filename + "_" + to_string(getpid()) + ".txt";
        tempFiles.push_back(tempFile);
        int fd = open(tempFile.c_str(), O_CREAT | O_WRONLY, 0600);

        pid_t pid = fork();
        if (pid == 0) {
            searchFile(searchpath, filename, recursive, caseInsensitive, fd);
            exit(EXIT_SUCCESS);
        } else if (pid > 0) {
            childPids.push_back(pid);
            close(fd);
        } else {
            cerr << "Fork failed" << endl;
            return EXIT_FAILURE;
        }
    }

    // Parent process waits for all child processes to terminate
    // This prevents zombie processes by reading the exit status of each child process
    for (pid_t pid : childPids) {
        waitpid(pid, nullptr, 0);
    }

    // Read and print the contents of each temporary file sequentially
    for (const auto& tempFile : tempFiles) {
        ifstream inFile(tempFile);
        cout << inFile.rdbuf();
        inFile.close();
        remove(tempFile.c_str()); // Remove the temporary file
    }

    return EXIT_SUCCESS;
}