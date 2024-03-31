#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Stock.h"

#include <iostream>
#include <string>
#include <vector>

class HashTable
{
public:
    HashTable();
    virtual ~HashTable();

    int hash(std::string key);
    void add(const Stock *stock);
    void remove(const Stock *stock);
    void search(const Stock *stock);
    void import(const Stock *stock);
    void plot(const Stock *stock);
    void save(const std::string filename);
    void load(const std::string filename);

    static const int TABLESIZE = 100;
    std::vector<std::vector<Stock>> table;
};

#endif // HASHTABLE_H
