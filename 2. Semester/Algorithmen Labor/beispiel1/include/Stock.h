#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <iostream>

class Stock
{
public:
    Stock(std::string name, std::string wkn, std::string acronym);
    virtual ~Stock();

    std::string name;
    std::string wkn;
    std::string acronym;
};

#endif // STOCK_H
