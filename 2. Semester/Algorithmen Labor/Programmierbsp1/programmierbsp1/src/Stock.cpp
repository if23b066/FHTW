#include <iostream>

#include "Stock.h"

Stock::Stock()
{
    // ctor
}

Stock::Stock(const std::string &name, const std::string &WKN, const std::string &symbol)
    : name(name), WKN(WKN), symbol(symbol) {}

void Stock::addData(const StockData &data)
{
    history.push_back(data);
}

void Stock::printLatestData() const
{
    if (!history.empty())
    {
        const StockData &latestData = history.back();
        // Print latest data
    }
    else
    {
        std::cout << "No data available for this stock." << std::endl;
    }
}

void Stock::plotData() const
{
    if (history.empty())
    {
        std::cout << "No data available for this stock." << std::endl;
        return;
    }

    // Create a temporary file to store the data
    std::ofstream dataFile("stock_data.txt");
    if (!dataFile)
    {
        std::cout << "Failed to create data file." << std::endl;
        return;
    }

    // Write the data to the file
    for (const StockData &data : history)
    {
        dataFile << data.x << " " << data.y << std::endl;
    }

    // Close the file
    dataFile.close();

    // Create a Gnuplot object
    Gnuplot gp;

    // Set the title of the plot
    gp << "set title 'Stock Data'" << std::endl;

    // Set the labels for the x and y axes
    gp << "set xlabel 'X'" << std::endl;
    gp << "set ylabel 'Y'" << std::endl;

    // Plot the data from the file
    gp << "plot 'stock_data.txt' with lines" << std::endl;
}

Stock::~Stock()
{
    // dtor
}
