#ifndef MINER_H
#define MINER_H

class Miner
{
public:
    Miner(int x, int y);
    virtual ~Miner();

    void move(char direction);
    void randomMove(char direction);

    int x;
    int y;
    char direction;
};

#endif // MINER_H
