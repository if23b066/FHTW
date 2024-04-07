#ifndef MINER_H
#define MINER_H

class Miner
{
public:
    Miner(int x, int y, int z, int score, int type);
    virtual ~Miner();

    void move(char direction);
    void randomMove(char direction);
    void moveDown();
    int getX() { return x; }
    int getY() { return y; }
    int getZ() { return z; }
    int getScore() { return score; }

private:
    int x;
    int y;
    int z;
    int score;
    int type;
    char direction;
};

#endif // MINER_H
