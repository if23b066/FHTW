#include "Programs.h"
#include "Stock.h"
#include "HashTable.h"

#include <iostream>
#include <string>

Programs::Programs()
{
    // ctor
}

void Programs::showMenu()
{
    std::cout << "ADD (a)\nDELETE(d)\nIMPORT(i)\nSEARCH(s)\nPLOT(p)\nSAVE(v)\nLOAD(l)\nQUIT(x)" << std::endl;
}

void Programs::reset()
{
    system("pause");
    system("cls");
}

void Programs::addFunction()
{
    std::string name;
    std::string wkn;
    std::string acronym;

    std::cout << "Enter the name of the stock: ";
    std::cin >> name;
    std::cout << "Enter the WKN of the stock: ";
    std::cin >> wkn;
    std::cout << "Enter the acronym of the stock: ";
    std::cin >> acronym;

    Stock *newStock = new Stock(name, wkn, acronym);
    hashtable.add(newStock);
}

void Programs::printTable()
{
    hashtable.print();
}

void Programs::removeFunction()
{
    std::string acronym;
    std::cout << "Enter the acronym of the stock you want to delete: ";
    std::cin >> acronym;

    Stock *stock = new Stock("", "", acronym);
    hashtable.remove(stock);
}

void Programs::importFunction()
{
    std::string acronym;
    std::cout << "Enter the acronym of the stock you want to import the data in: ";
    std::cin >> acronym;

    Stock *stock = new Stock("", "", acronym);
    hashtable.import(stock);
}

void Programs::searchFunction()
{
    std::string acronym;
    std::cout << "Enter the acronym of the stock you want to search: ";
    std::cin >> acronym;

    Stock *stock = new Stock("", "", acronym);
    hashtable.search(stock);
}

Programs::~Programs()
{
    // dtor
}
