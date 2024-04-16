#ifndef REISKOCHER_H
#define REISKOCHER_H

#include "Reis.h"
#include "Sushireis.h"
#include "Wildreis.h"

class Reiskocher
{
public:
    Reiskocher() : reis(nullptr) {}
    virtual ~Reiskocher()
    {
        delete reis;
    }

    void chooseRice();
    void cookRice();

private:
    Reis *reis;
};

#endif // REISKOCHER_H
