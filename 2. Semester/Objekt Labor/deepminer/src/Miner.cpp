#include <iostream>
#include <cstdlib>

#include "World.h"
#include "Miner.h"

Miner::Miner(int x, int y, int z, int score, int type)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->score = score;
    this->type = type;
}

void Miner::move(char direction)
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
    default:
        break;
    }
}

void Miner::randomMove(char direction)
{
    switch (direction)
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
        break;
    }
}

Miner::~Miner()
{
    // dtor
}
