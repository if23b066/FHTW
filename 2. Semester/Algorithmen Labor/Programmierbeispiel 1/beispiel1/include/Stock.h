#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <iostream>
#include <vector>

struct StockData
{
    std::string date;
    double open;
    double high;
    double low;
    double close;
    double adjClose;
    int volume;
};

class Stock
{
public:
    Stock(std::string name, std::string wkn, std::string acronym);
    virtual ~Stock();

    std::string name;
    std::string wkn;
    std::string acronym;
    std::vector<StockData> history;
};

#endif // STOCK_H
