#include "HashTable.h"

HashTable::HashTable()
{
    // ctor
}

HashTable::hashtable(std::string name, std::string wkn, std::string acronym)
{
    this->name = name;
    this->wkn = wkn;
    this->acronym = acronym;
}

HashTable::~HashTable()
{
    // dtor
}
