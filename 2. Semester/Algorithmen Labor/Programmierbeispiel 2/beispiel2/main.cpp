#include <iostream>
#include <string>

#include "Tree.h"

int main()
{
    std::string input;
    std::string filename;

    while (true)
    {
        system("cls");
        std::cout << "1. treecheck:         Check the tree (enter the filename afterwards)" << std::endl;
        std::cout << "2. force exit:        Exit the program" << std::endl;
        std::cout << "\nEnter command: ";
        std::cin >> input >> filename;

        if (input == "treecheck")
        {
            system("cls");
            Tree *tree = new Tree();
            tree->treecheck(&filename);
            system("pause");

            delete tree;
        }
        else if (input == "force")
        {
            return 0;
        }
        else
        {
            system("cls");
            std::cout << "Invalid input.\n\n";
            system("pause");
        }
    }

    return 0;
}
