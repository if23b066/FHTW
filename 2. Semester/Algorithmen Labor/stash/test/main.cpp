#include <iostream>

#include "Menu.h"
#include "HashTable.h"

int main()
{
    Menu *menu = new Menu();

    do
    {
        menu->showMenu();
        std::cout << "\nEnter your choice:" << std::endl;
        menu->selectProgram();
    } while (menu->choice != 'x');

    delete menu;
    return 0;
}
