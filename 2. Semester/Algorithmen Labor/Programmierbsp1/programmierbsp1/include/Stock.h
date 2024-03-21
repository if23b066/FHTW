#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <vector>

struct StockData
{
    std::string date;
    double open;
    double high;
    double low;
    double close;
    double volume;
    double adjClose;
};

class Stock
{
private:
    std::string name;
    std::string WKN;
    std::string symbol;
    std::vector<StockData> history;

public:
    Stock();

    Stock(const std::string &name, const std::string &WKN, const std::string &symbol);
    void addData(const StockData &data);
    void printLatestData() const;
    void plotData() const;

    ~Stock();
};

#endif
