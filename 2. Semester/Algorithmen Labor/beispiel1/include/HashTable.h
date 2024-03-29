#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Stock.h"

#include <vector>

class HashTable
{
public:
    HashTable();
    virtual ~HashTable();

    void add(std::string name, std::string wkn, std::string acronym);

private:
    std::vector<Stock> table;
};

#endif // HASHTABLE_H
