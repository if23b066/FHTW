#ifndef MENU_H
#define MENU_H

#include "HashTable.h"

class Menu : public HashTable
{
public:
    Menu();
    virtual ~Menu();

    void showMenu();
    void selectProgram();
    void reset();

    char choice;

protected:
private:
};

#endif // MENU_H
