#ifndef MINER_H
#define MINER_H

class Miner
{
public:
    Miner(int x, int y, int score, int type);
    virtual ~Miner();

    void move(char direction);
    void randomMove(char direction);

private:
    int x;
    int y;
    int score;
    int type;
    char direction;
};

#endif // MINER_H
