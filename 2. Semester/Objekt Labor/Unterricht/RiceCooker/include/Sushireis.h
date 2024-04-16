#ifndef SUSHIREIS_H
#define SUSHIREIS_H

#include <iostream>

#include "Reis.h"

class Sushireis : public Reis
{
public:
    Sushireis() : Reis(5) {}
    virtual ~Sushireis();

    void cook() override;
};

#endif // SUSHIREIS_H
