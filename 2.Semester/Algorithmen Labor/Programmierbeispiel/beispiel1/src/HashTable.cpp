#include "HashTable.h"
#include "Stock.h"
#include "Programs.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <limits>

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

void HashTable::remove(const Stock *stock)
{
    int index = hash(stock->acronym);
    if (table[index].empty())
    {
        std::cout << "\nStock not found!" << std::endl;
        return;
    }
    for (std::vector<Stock>::size_type i = 0; i < table[index].size(); i++)
    {
        if (table[index][i].acronym == stock->acronym)
        {
            table[index].erase(table[index].begin() + i);
        }
    }
    std::cout << "\nStock has been removed!" << std::endl;
}

void HashTable::import(const Stock *stock)
{
    int index = hash(stock->acronym);
    if (table[index].empty())
    {
        std::cout << "\nStock not found!" << std::endl;
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
                double adjClose;
                int volume;
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
                adjClose = std::stod(token);
                std::getline(ss, token, ',');
                volume = std::stoi(token);
                StockData data = {date, open, high, low, close, adjClose, volume};
                s.history.push_back(data);
            }
            file.close();
            std::cout << "\nStock has been imported!" << std::endl;
            return;
        }
    }
}

void HashTable::search(const Stock *stock)
{
    int index = hash(stock->acronym);
    if (table[index].empty())
    {
        std::cout << "\nStock not found!" << std::endl;
        return;
    }
    for (Stock s : table[index])
    {
        if (s.acronym == stock->acronym)
        {
            if (s.history.empty())
            {
                std::cout << "\nNo data available for " << stock->acronym << "." << std::endl;
                return;
            }
            else
            {
                StockData &latestData = s.history.back();
                std::cout << "\nLatest data for " << s.name << " (" << s.acronym << "):\n";
                std::cout << "--------------------------------" << std::endl;
                std::cout << "Date: " << latestData.date << ", Open: " << latestData.open << ", High: " << latestData.high
                          << ", Low: " << latestData.low << ", Close: " << latestData.close << ", Volume: " << latestData.volume
                          << ", Adj Close: " << latestData.adjClose << std::endl;
            }
        }
    }
}

void HashTable::plot(const Stock *stock)
{
    double minClose = std::numeric_limits<double>::max();

    int index = hash(stock->acronym);
    if (table[index].empty())
    {
        std::cout << "\nStock not found!" << std::endl;
        return;
    }
    for (Stock s : table[index])
    {
        if (s.acronym == stock->acronym)
        {
            if (s.history.empty())
            {
                std::cout << "\nNo data available for " << stock->acronym << "." << std::endl;
                return;
            }
            else
            {

                std::cout << "\nPlotting closing prices for " << stock->acronym << ":" << std::endl;
                std::cout << "--------------------------------" << std::endl;
                std::cout << "   Date         Close" << std::endl;
                for (int i = std::max(0, static_cast<int>(s.history.size()) - 30); i < s.history.size(); ++i)
                {
                    if (s.history[i].close < minClose)
                    {
                        minClose = s.history[i].close;
                    }
                }

                for (int i = std::max(0, static_cast<int>(s.history.size()) - 30); i < s.history.size(); ++i)
                {
                    std::cout << s.history[i].date << " " << std::fixed << std::setprecision(2) << std::setw(10) << s.history[i].close << " |";
                    int asterisks = static_cast<int>(std::round(s.history[i].close));
                    for (int j = minClose; j < asterisks; ++j)
                    {
                        std::cout << "*";
                    }
                    std::cout << std::endl;
                }
            }
        }
    }
}

void HashTable::save(const std::string filename)
{
    std::string filePath = "saves/" + filename + ".txt";

    std::ofstream outputFile(filePath);

    if (!outputFile.is_open())
    {
        std::cerr << "\nError: Unable to create or open file." << std::endl;
        return;
    }

    for (const auto &bucket : table)
    {
        for (const Stock &stock : bucket)
        {
            outputFile << stock.name << "," << stock.wkn << "," << stock.acronym << std::endl;
            for (const StockData &data : stock.history)
            {
                outputFile << data.date << "," << data.open << "," << data.high << "," << data.low << ","
                           << data.close << "," << data.volume << "," << data.adjClose << std::endl;
            }
            outputFile << std::endl;
        }
    }

    outputFile.close();
    std::cout << "\nData saved successfully to " << filePath << std::endl;
}

void HashTable::load(const std::string filename)
{
    std::string filePath = "saves/" + filename + ".txt";

    std::ifstream inputFile(filePath);

    if (!inputFile.is_open())
    {
        std::cerr << "\nError: Unable to open file." << std::endl;
        return;
    }

    std::string line;
    std::string stockName, wkn, acronym;
    std::vector<StockData> history;
    while (std::getline(inputFile, line))
    {
        if (line.empty())
        {
            if (!stockName.empty())
            {
                Stock stock(stockName, wkn, acronym);
                stock.history = history;
                add(&stock);
                stockName.clear();
                wkn.clear();
                acronym.clear();
                history.clear();
            }
        }
        else if (stockName.empty())
        {
            std::istringstream iss(line);
            std::getline(iss, stockName, ',');
            std::getline(iss, wkn, ',');
            std::getline(iss, acronym, ',');
        }
        else
        {
            std::istringstream iss(line);
            StockData data;
            std::string token;
            std::getline(iss, data.date, ',');
            std::getline(iss, token, ',');
            data.open = std::stod(token);
            std::getline(iss, token, ',');
            data.high = std::stod(token);
            std::getline(iss, token, ',');
            data.low = std::stod(token);
            std::getline(iss, token, ',');
            data.close = std::stod(token);
            std::getline(iss, token, ',');
            data.volume = std::stoi(token);
            std::getline(iss, token, ',');
            data.adjClose = std::stod(token);
            history.push_back(data);
        }
    }

    inputFile.close();
    std::cout << "\nData loaded successfully from " << filePath << std::endl;
}

HashTable::~HashTable()
{
    // dtor
}
