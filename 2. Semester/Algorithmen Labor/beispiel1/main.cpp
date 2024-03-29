#include <iostream>

#include "HashTable.h"
#include "Stock.h"
#include "Programs.h"

#include <iostream>
#include <vector>

int main()
{
    Programs program;

    char choice;
    switch (choice)
    {
    case 'a':
        system("cls");
        program.addFunction();
        std::cout << "\nStock has been added!" << std::endl;
        std::cout << "\n";
        break;
    case 'd':
        system("cls");
        // remove();
        std::cout << "\nStock has been deleted!" << std::endl;
        std::cout << "\n";
        break;
    case 'i':
        system("cls");
        // import();
        break;
    case 's':
        system("cls");
        // search();
        break;
    case 'p':
        system("cls");
        // plot();
        break;
    case 'v':
        system("cls");
        // save();
        break;
    case 'l':
        system("cls");
        // load();
        break;
    case 'x':
        break;
    default:
        std::cout << "Invalid choice" << std::endl;
        break;
    }

    return 0;
}
