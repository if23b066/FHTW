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

    std::cout << "Enter name: ";
    std::cin >> inputName;

    std::cout << "\nEnter WKN: ";
    std::cin >> inputWkn;

    while (true)
    {
        std::cout << "\nEnter acronym: ";
        std::cin >> inputAcro;
        if (inputAcro.length() > 0 && inputAcro.length() < 3)
        {
            break;
        }
        else
        {
            std::cout << "\nInvalid Input!" << std::endl;
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

void HashTable::search()
{
    std::string searchEntry;
    std::cout << "Enter the name or acronym to search: ";
    std::cin >> searchEntry;

    int index = hash(searchEntry.length());
    HashEntry *entry = table[index];
    while (entry != nullptr)
    {
        if (entry->name == searchEntry || entry->acro == searchEntry)
        {
            std::cout << "Entry found: " << entry->name << ", " << entry->wkn << ", " << entry->acro << std::endl;
            return;
        }
        entry = entry->next;
    }
    std::cout << "Entry not found." << std::endl;
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
