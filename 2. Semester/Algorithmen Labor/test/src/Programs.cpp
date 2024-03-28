#include "Programs.h"
#include "HashTable.h"

Programs::Programs()
{
    // ctor
}

int Programs::hash(int hashValue)
{
    int key = hashValue % HASH_SIZE;
    return key;
}

void Programs::add()
{
    std::string name, wkn, acronym;

    std::cout << "Enter name: ";
    std::cin >> name;

    std::cout << "\nEnter WKN: ";
    std::cin >> wkn;

    while (true)
    {
        std::cout << "\nEnter acronym: ";
        std::cin >> acronym;
        if (acronym.length() > 0 && acronym.length() < 3)
        {
            break;
        }
        else
        {
            std::cout << "\nInvalid Input!" << std::endl;
        }
    }
    HashTable *entry = new HashTable(name, wkn, acronym);

    int key = hash(std::stoi(wkn));
}

Programs::~Programs()
{
    // dtor
}
