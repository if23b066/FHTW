#include "Dimension.h"

#include <iostream>
#include <vector>

Dimension::Dimension()
{
    dimension.resize(width, std::vector<int>(length, 0));
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            dimension[i][j] = rand() % 9 + 1;
        }
    }
}

void Dimension::printDimension()
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            std::cout << dimension[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Dimension::~Dimension()
{
    // dtor
}
