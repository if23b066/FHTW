#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

#include "HashTable.h"

#define HASHSIZE 50

HashTable::HashTable() // Konstruktor
{
    for (int i = 0; i < HASHSIZE; ++i)
    {
        table[i] = nullptr;
    }
}

int HashTable::hash(int num) // Berechnung der Hashtabelle
{
    int key;
    return key = num % HASHSIZE;
}

void HashTable::add(const std::string &name, const std::string &wkn, const std::string &acro) // Hinzufügen eines Eintrags
{
    std::string inputName, inputWkn, inputAcro;

    while (true)
    {
        std::cout << "Enter name: ";
        std::cin >> inputName;
        if (inputName.length() > 0)
        {
            break;
        }
        else
        {
            std::cout << "Invalid Input!" << std::endl;
        }
    }

    while (true)
    {
        std::cout << "Enter WKN: ";
        std::cin >> inputWkn;
        if (inputWkn.length() > 0)
        {
            break;
        }
        else
        {
            std::cout << "Invalid Input!" << std::endl;
        }
    }

    while (true)
    {
        std::cout << "Enter acronym: ";
        std::cin >> inputAcro;
        if (inputAcro.length() > 0 && inputAcro.length() < 3)
        {
            break;
        }
        else
        {
            std::cout << "Invalid Input!" << std::endl;
        }
    }

    int num = rand() % 900 + 100; // generiert Zufälligen Schlüssel

    int index = hash(num);
    if (table[index] == nullptr)
    {
        table[index] = new HashEntry(inputName, inputWkn, inputAcro);
    }
    else
    {
        HashEntry *entry = table[index];
        while (entry->next != nullptr)
        {
            entry = entry->next;
        }
        entry->next = new HashEntry(inputName, inputWkn, inputAcro);
    }
}

HashTable::~HashTable() // Destruktor
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
