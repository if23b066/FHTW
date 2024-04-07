#include <iostream>
#include <cstdlib>

#include "Miner.h"

Miner::Miner(int x, int y, int score, int type)
{
    this->x = x;
    this->y = y;
    this->score = score;
    this->type = type;
}

void Miner::move(char direction)
{
    switch (direction)
    {
    case 'w':
    case 'W':
        if (y > 0)
        {
            y--;
        }
        break;
    case 's':
    case 'S':
        if (y < 4)
        {
            y++;
        }
        break;
    case 'a':
    case 'A':
        if (x > 0)
        {
            x--;
        }
        break;
    case 'd':
    case 'D':
        if (x > 4)
        {
            x++;
        }
        break;
    case 'x':
    case 'X':
        break;
    default:
        break;
    }
}

void Miner::randomMove(char direction)
{
    direction = rand() % 4;

    switch (direction)
    {
    case 0:
        if (y > 0)
        {
            y--;
        }
        break;
    case 1:
        if (y < 4)
        {
            y++;
        }
        break;
    case 2:
        if (x > 0)
        {
            x--;
        }
        break;
    case 3:
        if (x < 4)
        {
            x++;
        }
        break;
    default:
        break;
    }
}

Miner::~Miner()
{
    // dtor
}
