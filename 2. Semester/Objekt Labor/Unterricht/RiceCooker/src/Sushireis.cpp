#include <iostream>

#include "Sushireis.h"
#include "Reis.h"

void Sushireis::cook()
{
    Reis::cook();
    std::cout << "Sushirice is finished cooking!\n";
    int cooldown;
    std::cout << "How long do you want to cool it? (1-9 Minutes)\n";
    std::cin >> cooldown;
    for (int i = 0; i < cooldown; i++)
    {
        std::cout << "Still cooling for " << i << "minutes\n";
    }
    std::cout << "Sushirice is finished cooling!\n";
}