#ifndef BOTS_H
#define BOTS_H

#include "Dimension.h"

class Bots
{
public:
    Bots();
    virtual ~Bots();

    int sumField(Dimension *dimension);

private:
    int x = 0;
    int y = 0;
};

#endif // BOTS_H
