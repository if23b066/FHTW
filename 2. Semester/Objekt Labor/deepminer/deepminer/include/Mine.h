#ifndef MINE_H
#define MINE_H

class Mine
{
public:
    Mine();

    void createMine();

    virtual ~Mine();

protected:
private:
    int field[5][5][10];
};

#endif // MINE_H
