#include <iostream>

#include "Player.h"
#include "World.h"
#include "Enemy.h"

Player::Player(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Player::move(char direction)
{
    switch(direction)
    {
        case 'W':
        case 'w':
            if(y > 0)
            {
                y--;
            }
            break;
        case 'A':
        case 'a':
            if(x > 0)
            {
                x--;
            }
            break;
        case 'S':
        case 's':
            if(y < 4)
            {
                y++;
            }
            break;
        case 'D':
        case 'd':
            if(x < 4)
            {
                x++;
            }
            break;
        default:
            break;
    }
}

void Player::render()
{
    std::cout << 'X';
}

void Player::activeField(World* world, Enemy* enemy)
{
    int danger = rand() % 6;

    switch(world->world[y][x])
    {
    case '_':
        std::cout << "Nichts passiert!\n" << std::endl;
        break;
    case 'G':
        std::cout << "Gefährliche Situation!\n" << std::endl;
        if(danger < difficulty)
        {
            hp--;
            std::cout << "Du hast 1HP verloren!\n" << std::endl;
        }
        else
        {
            std::cout << "Glück gehabt, nichts passiert!\n" << std::endl;
        }
        break;
    case 'B':
        if(hp >= 5)
        {
            std::cout << "Du hast schon volle HP!\n" << std::endl;
        }
        else
        {
            std::cout << "Du ruhst dich aus und erhälst 1HP!\n" << std::endl;
            hp++;
        }
        break;
    case 'R':
        std::cout << "Du hast ein Relikt gefunden!\n" << std::endl;
        colRelics++;
        world->relics--;
        if(world->relics == 0)
        {
            std::cout << "Level geschafft!\n" << std::endl;
        }
        break;
    }
    if(x == enemy->x && y == enemy->y)
    {
        std::cout << "Du hast 1HP durch einen Gegner verloren!\n" << std::endl;
        hp--;
    }
}

void Player::resetPlayer()
{
    x = 0;
    y = 0;
}
