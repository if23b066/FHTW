#include "HashTable.h"

#include <iostream>
#include <string>
#include <vector>

HashTable::HashTable()
{
    table.resize(100);
}

void HashTable::add(std::string name, std::string wkn, std::string acronym)
{
    Stock stock(name, wkn, acronym);
    table.push_back(stock);
}

HashTable::~HashTable()
{
    // dtor
}
