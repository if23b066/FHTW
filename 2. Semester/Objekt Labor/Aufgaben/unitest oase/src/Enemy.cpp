#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Enemy.h"
#include "Player.h"
#include "World.h"

Enemy::Enemy()
{
    srand(time(NULL));

    x = 1 + rand() % 3;
    y = 1 + rand() % 3;
}

void Enemy::renderEnemy()
{
    std::cout << "#";
}

void Enemy::enemyMove()
{
    int direction = rand() % 5;

    switch(direction)
    {
    case 0:
        if(y > 0)
        {
            y--;
        }
        break;
    case 1:
        if(x > 0)
        {
            x--;
        }
        break;
    case 2:
        if(y < 4)
        {
            y++;
        }
        break;
    case 3:
        if(x < 4)
        {
            x++;
        }
        break;
    case 4:
        break;
    default:
        throw std::invalid_argument("Invalid move");
    }
}

void Enemy::resetEnemy()
{
    x = 4;
    y = 4;
}
