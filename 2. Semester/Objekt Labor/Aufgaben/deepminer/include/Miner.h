#ifndef MINER_H
#define MINER_H

class Miner
{
public:
    Miner(int x, int y, int score, int type);
    virtual ~Miner();

    int move(char direction);
    int randomMove();
    int getX() { return x; }
    int getY() { return y; }
    int getScore() { return score; }
    int getType() { return type; }
    void setScore(int score) { this->score = score; }

private:
    int x;
    int y;
    int score;
    int type;
    char direction;
};

#endif // MINER_H
