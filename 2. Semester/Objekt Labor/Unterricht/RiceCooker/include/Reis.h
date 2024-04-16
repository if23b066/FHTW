#ifndef REIS_H
#define REIS_H

class Reis
{
public:
    Reis(int kochzeit) : kochzeit(kochzeit) {}

    virtual void cook();
    int getKochzeit() { return kochzeit; }

private:
    int kochzeit;
};

#endif // REIS_H
