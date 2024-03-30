#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <unordered_map>

using namespace std;

struct StockData
{
    string date;
    double open;
    double high;
    double low;
    double close;
    int volume;
    double adjClose;
};

struct Stock
{
    string name;
    string wkn;
    string kuerzel;
    vector<StockData> history;
};

class StockManager
{
private:
    unordered_map<string, Stock> stocks;

public:
    void addStock(const string &name, const string &wkn, const string &kuerzel)
    {
        stocks[kuerzel] = {name, wkn, kuerzel, {}};
    }

    void deleteStock(const string &kuerzel)
    {
        stocks.erase(kuerzel);
    }

    void importData(const string &kuerzel, const string &filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cerr << "Error: Unable to open file " << filename << endl;
            return;
        }

        // Skip the header line
        string header;
        getline(file, header);

        // Find stock by its kuerzel
        auto it = stocks.find(kuerzel);
        if (it == stocks.end())
        {
            cerr << "Error: Stock with kuerzel " << kuerzel << " not found." << endl;
            return;
        }

        Stock &stock = it->second;

        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string token;
            StockData data;

            // Read each token separated by commas
            getline(ss, token, ',');
            // cout << "Token: " << token << endl;
            data.date = token;
            getline(ss, token, ',');
            // cout << "Token: " << token << endl; // Debug output
            data.open = stod(token);
            getline(ss, token, ',');
            // cout << "Token: " << token << endl;
            data.high = stod(token);
            getline(ss, token, ',');
            // cout << "Token: " << token << endl;
            data.low = stod(token);
            getline(ss, token, ',');
            // cout << "Token: " << token << endl;
            data.close = stod(token);
            getline(ss, token, ',');
            // cout << "Token: " << token << endl;
            data.adjClose = stod(token);
            getline(ss, token, ',');
            // cout << "Token: " << token << endl;
            data.volume = stoi(token);

            stock.history.push_back(data);
        }

        file.close();
    }

    void searchStock(const string &key)
    {
        auto it = stocks.find(key);
        if (it != stocks.end())
        {
            Stock &stock = it->second;
            if (!stock.history.empty())
            {
                StockData &latestData = stock.history.back();
                cout << "Latest data for " << stock.name << " (" << stock.kuerzel << "):\n";
                cout << "Date: " << latestData.date << ", Open: " << latestData.open << ", High: " << latestData.high
                     << ", Low: " << latestData.low << ", Close: " << latestData.close << ", Volume: " << latestData.volume
                     << ", Adj Close: " << latestData.adjClose << endl;
            }
            else
            {
                cout << "No data available for " << stock.name << " (" << stock.kuerzel << ")." << endl;
            }
        }
        else
        {
            cout << "Stock with key " << key << " not found." << endl;
        }
    }

    void plotStock(const string &kuerzel)
    {
        auto it = stocks.find(kuerzel);
        if (it != stocks.end())
        {
            Stock &stock = it->second;
            cout << "Plotting data for " << stock.name << " (" << stock.kuerzel << "):\n";

            // �berpr�fen, ob gen�gend Daten vorhanden sind
            if (stock.history.size() < 30)
            {
                cout << "Not enough data available for plotting." << endl;
                return;
            }

            // Finden des maximalen und minimalen Schlusskurses
            double maxClose = stock.history.back().close;
            double minClose = stock.history.back().close;
            string maxDate = stock.history.back().date;
            string minDate = stock.history.back().date;
            for (int i = stock.history.size() - 30; i < stock.history.size(); ++i)
            {
                if (stock.history[i].close > maxClose)
                {
                    maxClose = stock.history[i].close;
                    maxDate = stock.history[i].date;
                }
                if (stock.history[i].close < minClose)
                {
                    minClose = stock.history[i].close;
                    minDate = stock.history[i].date;
                }
            }

            // Skalierung der Daten
            int yScale = 10;                          // Anzahl der Zeilen f�r das Diagramm
            int xScale = 30;                          // Anzahl der Spalten f�r das Diagramm
            int days = stoi(maxDate) - stoi(minDate); // Anzahl der Tage zwischen den Datumsangaben
            double yStep = (days != 0) ? yScale / days : 0;
            double xStep = (maxClose != minClose) ? xScale / (maxClose - minClose) : 0;

            // Ausgabe der Achsenbeschriftungen
            cout << "Datum";
            cout << string(xScale - 5, ' ') << "Kurs" << endl;

            // Ausgabe der Daten
            for (int i = stock.history.size() - 30; i < stock.history.size(); ++i)
            {
                int yPos = static_cast<int>((stoi(stock.history[i].date) - stoi(minDate)) * yStep);
                int xPos = static_cast<int>((stock.history[i].close - minClose) * xStep);
                cout << setw(yScale) << stock.history[i].date << "| ";
                cout << string(yPos, '\n') << setw(xPos) << "* " << stock.history[i].close << endl;
            }
        }
        else
        {
            cout << "Stock with kuerzel " << kuerzel << " not found." << endl;
        }
    }

    void saveToFile(const string &filename)
    {
        ofstream file(filename);
        if (file.is_open())
        {
            for (const auto &pair : stocks)
            {
                const Stock &stock = pair.second;
                file << stock.name << "," << stock.wkn << "," << stock.kuerzel << endl;
                for (const StockData &data : stock.history)
                {
                    file << data.date << "," << data.open << "," << data.high << "," << data.low << ","
<< data.close << "," << data.volume << "," << data.adjClose << endl;
                }
                file << endl; // separate stocks by an empty line
            }
            file.close();
            cout << "Data saved to " << filename << endl;
        }
        else
        {
            cout << "Unable to open file " << filename << " for saving." << endl;
        }
    }

    void loadFromFile(const string &filename)
    {
        ifstream file(filename);
        if (file.is_open())
        {
            stocks.clear(); // clear existing data before loading
            string line;
            Stock stock;
            while (getline(file, line))
            {
                if (line.empty())
                {
                    if (!stock.kuerzel.empty())
                    {
                        stocks[stock.kuerzel] = stock;
                        stock = Stock();
                    }
                }
                else
                {
                    if (stock.kuerzel.empty())
                    {
                        // Read stock info
                        size_t pos = line.find(',');
                        stock.name = line.substr(0, pos);
                        line.erase(0, pos + 1);
                        pos = line.find(',');
                        stock.wkn = line.substr(0, pos);
                        line.erase(0, pos + 1);
                        stock.kuerzel = line;
                    }
                    else
                    {
                        // Read stock data
                        StockData data;
                        size_t pos = line.find(',');
                        data.date = line.substr(0, pos);
                        line.erase(0, pos + 1);
                        data.open = stod(line.substr(0, pos));
                        line.erase(0, pos + 1);
                        data.high = stod(line.substr(0, pos));
                        line.erase(0, pos + 1);
                        data.low = stod(line.substr(0, pos));
                        line.erase(0, pos + 1);
                        data.close = stod(line.substr(0, pos));
                        line.erase(0, pos + 1);
                        data.volume = stoi(line.substr(0, pos));
                        line.erase(0, pos + 1);
                        data.adjClose = stod(line);
                        stock.history.push_back(data);
                    }
                }
            }
            file.close();
            cout << "Data loaded from " << filename << endl;
        }
        else
        {
            cout << "Unable to open file " << filename << " for loading." << endl;
        }
    }
};

int main()
{
    StockManager manager;
    int choice;
    string kuerzel, name, wkn, filename;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. ADD\n";
        cout << "2. DEL\n";
        cout << "3. IMPORT\n";
        cout << "4. SEARCH\n";
        cout << "5. PLOT\n";
        cout << "6. SAVE <filename>\n";
        cout << "7. LOAD <filename>\n";
        cout << "8. QUIT\n";
        cout << "Auswahl: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Eingabe der Aktien-Informationen: " << endl;
            cout << "Name: ";
            cin >> name;
            cout << "Wertpapierkennnummer: ";
            cin >> wkn;
            cout << "Kuerzel: ";
            cin >> kuerzel;
            // cin >> name >> wkn >> kuerzel;
            manager.addStock(name, wkn, kuerzel);
            cout << endl
                 << "Aktie " << name << "(" << kuerzel << ") hinzugefuegt." << endl;
            break;
        case 2:
            cout << "Kuerzel der zu l�schenden Aktie: ";
            cin >> kuerzel;
            manager.deleteStock(kuerzel);
            cout << "Aktie geloescht." << endl;
            break;
        case 3:
            cout << "Enter kuerzel of the stock and filename: ";
            cin >> kuerzel >> filename;
            manager.importData(kuerzel, filename);
            break;
        case 4:
            cout << endl
                 << "Name oder Kuerzel der zu suchenden Aktie: ";
            cin >> kuerzel;
            manager.searchStock(kuerzel);
            break;
        case 5:
            cout << endl
                 << "30-Tage-Kurs, Kuerzel?: ";
            cin >> kuerzel;
            manager.plotStock(kuerzel);
            break;
        case 6:
            cout << "Enter filename to save: ";
            cin >> filename;
            manager.saveToFile(filename);
            break;
        case 7:
            cout << "Enter filename to load: ";
            cin >> filename;
            manager.loadFromFile(filename);
            break;
        case 8:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
