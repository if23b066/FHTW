#include "HashTable.h"
#include "Stock.h"
#include "Programs.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

HashTable::HashTable()
{
    table.resize(TABLESIZE);
}

int HashTable::hash(std::string key)
{
    int hash = 0;
    for (char c : key)
    {
        hash += c;
    }
    int index = hash % TABLESIZE;
    return index;
}

void HashTable::add(const Stock *stock)
{
    int index = hash(stock->acronym);
    table[index].push_back(*stock);
}

void HashTable::print()
{
    for (int i = 0; i < TABLESIZE; i++)
    {
        std::cout << i << ": ";
        for (Stock stock : table[i])
        {
            std::cout << stock.acronym << " ";
        }
        std::cout << std::endl;
    }
}

void HashTable::remove(const Stock *stock)
{
    int index = hash(stock->acronym);
    if (table[index].empty())
    {
        std::cout << "Stock not found!" << std::endl;
        return;
    }
    for (std::vector<Stock>::size_type i = 0; i < table[index].size(); i++)
    {
        if (table[index][i].acronym == stock->acronym)
        {
            table[index].erase(table[index].begin() + i);
        }
    }
}

void HashTable::import(const Stock *stock)
{
    int index = hash(stock->acronym);
    if (table[index].empty())
    {
        std::cout << "Stock not found!" << std::endl;
        return;
    }
    for (Stock &s : table[index])
    {
        if (s.acronym == stock->acronym)
        {
            std::ifstream file("file/" + stock->acronym + ".csv");
            if (!file.is_open())
            {
                std::cout << "File not found!" << std::endl;
                return;
            }

            std::string header;
            getline(file, header);

            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream ss(line);
                std::string date;
                double open;
                double high;
                double low;
                double close;
                int volume;
                double adjClose;
                std::string token;
                std::getline(ss, token, ',');
                date = token;
                std::getline(ss, token, ',');
                open = std::stod(token);
                std::getline(ss, token, ',');
                high = std::stod(token);
                std::getline(ss, token, ',');
                low = std::stod(token);
                std::getline(ss, token, ',');
                close = std::stod(token);
                std::getline(ss, token, ',');
                volume = std::stoi(token);
                std::getline(ss, token, ',');
                adjClose = std::stod(token);
                StockData data = {date, open, high, low, close, volume, adjClose};
                s.history.push_back(data);
            }
            file.close();
            return;
        }
    }
}

void HashTable::search(const Stock *stock)
{
    int index = hash(stock->acronym);
    if (table[index].empty())
    {
        std::cout << "Stock not found!" << std::endl;
        return;
    }
    for (Stock s : table[index])
    {
        if (s.acronym == stock->acronym)
        {
            if (s.history.empty())
            {
                std::cout << "No data available for " << stock->acronym << "." << std::endl;
                return;
            }
            else
            {
                std::cout << "Data for " << stock->name << " (" << stock->acronym << "):" << std::endl;
                for (StockData data : s.history)
                {
                    std::cout << data.date << " " << data.open << " " << data.high << " " << data.low << " " << data.close << " " << data.volume << " " << data.adjClose << std::endl;
                }
            }
        }
    }
}

HashTable::~HashTable()
{
    // dtor
}
