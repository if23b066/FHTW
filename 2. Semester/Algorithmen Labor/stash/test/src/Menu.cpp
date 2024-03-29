#include <iostream>
#include <string>

#include "Menu.h"

Menu::Menu()
{
    // ctor
}

void Menu::showMenu()
{
    std::cout << "ADD (a)\nDELETE(d)\nIMPORT(i)\nSEARCH(s)\nPLOT(p)\nSAVE(v)\nLOAD(l)\nQUIT(x)" << std::endl;
}

void Menu::selectProgram()
{
    std::cin >> choice;

    switch (choice)
    {
    case 'a':
        system("cls");
        add();
        std::cout << "\nStock has been added!" << std::endl;
        std::cout << "\n";
        reset();
        break;
    case 'd':
        system("cls");
        // remove();
        std::cout << "\nStock has been deleted!" << std::endl;
        std::cout << "\n";
        reset();
        break;
    case 'i':
        system("cls");
        // import();
        break;
    case 's':
        system("cls");
        // search();
        reset();
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
}

void Menu::reset()
{
    system("pause");
    system("cls");
}

Menu::~Menu()
{
    // dtor
}
