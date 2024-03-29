#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>
#include <vector>

class HashTable
{
public:
    HashTable();
    virtual ~HashTable();

    HashTable(std::string name, std::string wkn, std::string acronym);

    std::string name;
    std::string wkn;
    std::string acronym;

private:
    static const int HASH_SIZE = 50;
    std::vector<HashTable> hashTable[HASH_SIZE];
};

#endif // HASHTABLE_H
