#include <iostream>
#include <fstream>
#include <sstream>

#include "HashTable.h"

#define HASHSIZE 20

HashTable::HashTable()
{
    for (int i = 0; i < HASHSIZE; ++i)
    {
        table[i] = nullptr;
    }
}

int HashTable::hash(const std::string &key)
{
    int hash = 0;
    for (char c : key)
    {
        hash += c;
    }
    return hash % HASHSIZE;
}

void HashTable::manualInput()
{
    std::string key, name, wkn, acro;
    int value;

    std::cout << "Enter key: ";
    std::cin >> key;

    std::cout << "Enter name: ";
    std::cin >> name;

    std::cout << "Enter WKN: ";
    std::cin >> wkn;

    std::cout << "Enter acronym: ";
    std::cin >> acro;

    std::cout << "Enter value: ";
    std::cin >> value;

    add(key, name, wkn, acro, value);
}

void HashTable::add(const std::string &key, const std::string &name, const std::string &wkn, const std::string &symbol, int value)
{
    int index = hash(key);
    if (table[index] == nullptr)
    {
        table[index] = new HashEntry(key, name, wkn, symbol, value);
    }
    else
    {
        HashEntry *entry = table[index];
        while (entry->next != nullptr)
        {
            entry = entry->next;
        }
        entry->next = new HashEntry(key, name, wkn, symbol, value);
    }
}

HashTable::~HashTable()
{
    for (int i = 0; i < HASHSIZE; ++i)
    {
        HashEntry *entry = table[i];
        while (entry != nullptr)
        {
            HashEntry *prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
}
