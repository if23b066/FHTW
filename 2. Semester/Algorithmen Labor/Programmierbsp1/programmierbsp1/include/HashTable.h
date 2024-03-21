#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>
#include "Stock.h"

class HashTable
{
private:
    static const int TABLE_SIZE = 100; // Adjust size as needed
    std::vector<Stock> table[TABLE_SIZE];

    int hashFunction(const std::string &key) const;

public:
    HashTable();

    void addStock(const Stock &stock);
    void deleteStock(const std::string &key);
    Stock *searchStock(const std::string &key);

    ~HashTable();
};

#endif
