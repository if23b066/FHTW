#include "HashTable.h"

HashTable::HashTable()
{
    // ctor
}

int HashTable::hashFunction(const std::string &key) const
{
    int hash = 0;
    for (int i = 0; i < key.length(); i++)
    {
        hash = (hash + key[i]) % TABLE_SIZE;
    }
    return hash;
}

void HashTable::addStock(const Stock &stock)
{
    int index = hashFunction(stock.symbol);
    table[index].push_back(stock);
}

void HashTable::deleteStock(const std::string &key)
{
    int index = hashFunction(key);
    table[index].remove_if([&](const Stock &s)
                           { return s.symbol == key; });
}

Stock *HashTable::searchStock(const std::string &key)
{
    int index = hashFunction(key);
    for (auto &stock : table[index])
    {
        if (stock.symbol == key)
        {
            return &stock;
        }
    }
    return nullptr;
}

HashTable::~HashTable()
{
    // dtor
}
