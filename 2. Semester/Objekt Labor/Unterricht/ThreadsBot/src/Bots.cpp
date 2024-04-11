#include "Bots.h"
#include "Dimension.h"

#include <iostream>

Bots::Bots()
{
    // ctor
}

int Bots::sumField(Dimension *dimension)
{
    int sum = 0;
    for (int i = 0; i < dimension->getWidth(); i++)
    {
        for (int j = 0; j < dimension->getLength(); j++)
        {
            sum += dimension[i][j];
        }
    }
    return sum;
}

Bots::~Bots()
{
    // dtor
}
