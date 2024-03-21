#ifndef MENU_H
#define MENU_H

#include "HashTable.h"

class Menu
{
private:
    HashTable table;

public:
    Menu();

    void displayMenu();

    ~Menu();
};

#endif
