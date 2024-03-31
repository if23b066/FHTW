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
    void removeFunction();
    void searchFunction();
    void importFunction();
    void plotFunction();
    void saveFunction();
    void loadFunction();

private:
    HashTable hashtable;
};

#endif // PROGRAMS_H
