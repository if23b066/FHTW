#include "Dimension.h"
#include "Bots.h"

#include <iostream>

int main()
{
    Dimension dimension;
    Bots *bot1 = new Bots();
    // dimension.printDimension();
    std::cout << bot1->sumField(&dimension) << std::endl;

    delete bot1;
    return 0;
}
