#ifndef MENU_H
#define MENU_H

#include "HashTable.h"
#include "Programs.h"

class Menu : public Programs
{
public:
    Menu();
    virtual ~Menu();

    void showMenu();
    void selectProgram();
    void reset();

    char choice;
};

#endif // MENU_H
