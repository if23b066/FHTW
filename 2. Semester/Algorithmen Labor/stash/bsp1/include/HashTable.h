#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>

class HashTable
{
public:
    HashTable();
    virtual ~HashTable();

    std::string name;
    std::string wkn;
    std::string acronym;
};

#endif // HASHTABLE_H
