#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Tree.h"

void Tree::treecheck(std::string *filename)
{
    system("cls");
    std::string filePath = "files/" + *filename;
    std::ifstream inputFile(filePath);
    std::string line;

    if (inputFile.is_open())
    {
        std::cout << "File: " << *filename << ":\n\n";

        while (std::getline(inputFile, line))
        {
            std::cout << line << std::endl;
        }
        std::cout << "\n";
        inputFile.close();
    }
    else
    {
        std::cout << "Failed to open the file. Check if the files is included in the \"files\" folder\n\n";
    }
}