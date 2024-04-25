#include <iostream>
#include <string>

#include "Tree.h"

int main()
{
    std::string input;

    while (true)
    {
        system("cls");
        std::cout << "1. treecheck:     Check the tree" << std::endl;
        std::cout << "2. exit:          Exit the program" << std::endl;
        std::cout << "\nEnter command: ";
        std::cin >> input;

        if (input == "treecheck")
        {
            system("cls");
            Tree *tree = new Tree();
            tree->treecheck();
            system("pause");

            delete tree;
        }
        else if (input == "exit")
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
