#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

#define HASHSIZE 50

struct HashEntry
{
    std::string name; // Aktienname
    std::string wkn;  // Wertpapierkennnummer
    std::string acro; // Aktienkürzel
    HashEntry *next;
    HashEntry(const std::string &name, const std::string &wkn, const std::string &acro)
        : name(name), wkn(wkn), acro(acro), next(nullptr) {}
};

class HashTable
{
public:
    HashTable();
    virtual ~HashTable();

    int hash(int key);
    void add(const std::string &name, const std::string &wkn, const std::string &acro);
    void search();

protected:
private:
    HashEntry *table[HASHSIZE];
};

#endif // HASHTABLE_H
