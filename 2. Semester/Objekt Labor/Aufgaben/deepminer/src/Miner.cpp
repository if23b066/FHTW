#include <iostream>
#include <cstdlib>

#include "World.h"
#include "Miner.h"

Miner::Miner(int x, int y, int score, int type)
{
    this->x = x;
    this->y = y;
    this->score = score;
    this->type = type;
}

int Miner::move(char direction)
{
    switch (direction)
    {
    case 'W':
    case 'w':
        if (y > 0)
        {
            y--;
        }
        break;
    case 'A':
    case 'a':
        if (x > 0)
        {
            x--;
        }
        break;
    case 'S':
    case 's':
        if (y < 4)
        {
            y++;
        }
        break;
    case 'D':
    case 'd':
        if (x < 4)
        {
            x++;
        }
        break;
    case 'F':
    case 'f':
        break;
    default:
        return 1;
        break;
    }
    return 0;
}

int Miner::randomMove()
{
    int random = rand() % 5;
    switch (random)
    {
    case 0:
        if (y > 0)
        {
            y--;
        }
        break;
    case 1:
        if (x > 0)
        {
            x--;
        }
        break;
    case 2:
        if (y < 4)
        {
            y++;
        }
        break;
    case 3:
        if (x < 4)
        {
            x++;
        }
        break;
    case 4:
        break;
    default:
        return 1;
        break;
    }
    return 0;
}

Miner::~Miner()
{
    // dtor
}
