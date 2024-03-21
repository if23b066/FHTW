#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

#define HASHSIZE 20

struct HashEntry
{
    std::string key;
    std::string name; // Aktienname
    std::string wkn;  // Wertpapierkennnummer
    std::string acro; // Aktienkürzel
    int value;
    HashEntry *next;
    HashEntry(const std::string &key, const std::string &name, const std::string &wkn, const std::string &acro, int value)
        : key(key), name(name), wkn(wkn), acro(acro), value(value), next(nullptr) {}
};

class HashTable
{
public:
    HashTable();
    virtual ~HashTable();

    int hash(const std::string &key);
    void add(const std::string &key, const std::string &name, const std::string &wkn, const std::string &symbol, int value);
    void manualInput();

protected:
private:
    HashEntry *table[HASHSIZE];
};

#endif // HASHTABLE_H
