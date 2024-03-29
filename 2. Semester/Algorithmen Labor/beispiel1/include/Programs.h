#ifndef PROGRAMS_H
#define PROGRAMS_H

#include "HashTable.h"
#include "Stock.h"

class Programs
{
public:
    Programs();
    virtual ~Programs();

    void addFunction();

private:
    HashTable hashtable;
};

#endif // PROGRAMS_H
