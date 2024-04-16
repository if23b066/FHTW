#include <iostream>

#include "Wildreis.h"
#include "Reis.h"

void Wildreis::cook()
{
    Reis::cook();
    std::cout << "Wildrice is finished cooking!\n";
}
