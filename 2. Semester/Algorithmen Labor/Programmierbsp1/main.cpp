#include <iostream>

#include "Menu.h"
#include "HashTable.h"

#define HASHSIZE 20

int main()
{
    Menu *menu = new Menu;
    HashTable *hashtable = new HashTable;

    do
    {
        menu->showMenu();
        std::cout << "\nEnter your choice:" << std::endl;
        menu->selectProgram();
    } while (menu->choice != 'x');

    delete hashtable;
    delete menu;
    return 0;
}
