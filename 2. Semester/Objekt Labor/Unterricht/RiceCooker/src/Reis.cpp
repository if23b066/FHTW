#include <iostream>

#include "Reis.h"

void Reis::cook()
{
    for (int i = 0; i < getKochzeit(); i--)
    {
        std::cout << "Still cooking for " << i << "minutes\n";
    }
}
