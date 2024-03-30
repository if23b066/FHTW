#ifndef PROGRAMS_H
#define PROGRAMS_H

#include "HashTable.h"
#include "Stock.h"

class Programs
{
public:
    Programs();
    virtual ~Programs();

    void reset();
    void showMenu();
    void addFunction();
    void printTable();
    void removeFunction();
    void searchFunction();
    void importFunction();

private:
    HashTable hashtable;
};

#endif // PROGRAMS_H
