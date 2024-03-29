#include "Programs.h"

Programs::Programs()
{
    // ctor
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
    hashtable.add(name, wkn, acronym);
}

Programs::~Programs()
{
    // dtor
}
