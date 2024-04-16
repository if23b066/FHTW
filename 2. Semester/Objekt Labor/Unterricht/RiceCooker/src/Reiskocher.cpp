#include "Reiskocher.h"

void Reiskocher::chooseRice()
{
    int choice;
    std::cout << "Choose your rice: (1) Sushireis, (2) Wildreis\n";
    std::cin >> choice;

    if (choice == 1)
    {
        reis = new Sushireis();
    }
    else if (choice == 2)
    {
        reis = new Wildreis();
    }
    else
    {
        std::cout << "Invalid choice\n";
    }
}

void Reiskocher::cookRice()
{
    if (reis == nullptr)
    {
        std::cout << "No rice chosen\n";
        return;
    }
    reis->cook();
}