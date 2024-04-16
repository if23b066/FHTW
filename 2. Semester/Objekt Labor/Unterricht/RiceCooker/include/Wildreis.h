#ifndef WILDREIS_H
#define WILDREIS_H

#include <iostream>

#include "Reis.h"

class Wildreis : public Reis
{
public:
    Wildreis() : Reis(10) {}

    void cook() override;
};

#endif // WILDREIS_H
