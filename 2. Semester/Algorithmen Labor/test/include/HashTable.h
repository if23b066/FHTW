#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

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
};

#endif // HASHTABLE_H
