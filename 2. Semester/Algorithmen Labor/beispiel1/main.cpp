#include <iostream>

#include "HashTable.h"
#include "Stock.h"
#include "Programs.h"

#include <iostream>

int main()
{
    Programs program;

    while (true)
    {
        program.showMenu();
        char choice;
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 'a':
            system("cls");
            program.addFunction();
            std::cout << "\nStock has been added!" << std::endl;
            std::cout << "\n";
            program.printTable();
            program.reset();
            break;
        case 'd':
            system("cls");
            program.removeFunction();
            program.printTable();
            program.reset();
            break;
        case 'i':
            system("cls");
            program.importFunction();
            program.reset();
            break;
        case 's':
            system("cls");
            program.searchFunction();
            program.reset();
            break;
        case 'p':
            system("cls");
            program.plotFunction();
            program.reset();
            break;
        case 'v':
            system("cls");
            program.saveFunction();
            program.reset();
            break;
        case 'l':
            system("cls");
            program.loadFunction();
            program.reset();
            break;
        case 'x':
            return 0;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
    }

    return 0;
}
