#include "World.h"
#include "Miner.h"
#include "Functions.h"

#include <iostream>
#include <ctime>

World::World(int gamemode)
{
    srand(time(NULL));

    world.resize(length, std::vector<std::vector<int>>(width, std::vector<int>(height, 'X')));
    for (int z = 0; z < height; z++)
    {
        for (int y = 0; y < width; y++)
        {
            for (int x = 0; x < length; x++)
            {
                world[x][y][z] = rand() % 9 + 1;
            }
        }
    }
    this->gamemode = gamemode;
}

void World::printWorld(Miner *player, Miner *enemy)
{
    int z = 9;
    std::cout << "\033c";
    std::cout << "+";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "--";
    }
    std::cout << "-+" << std::endl;
    for (int y = 0; y < width; y++)
    {
        std::cout << "| ";
        for (int x = 0; x < length; x++)
        {
            if ((player->getX() == x) && (enemy->getX() == x) && (player->getY() == y) && (enemy->getY() == y))
            {
                std::cout << "\033[1;33m" << world[x][y][z] << "\033[0m ";
            }
            else if (player->getX() == x && player->getY() == y)
            {
                std::cout << "\033[1;31m" << world[x][y][z] << "\033[0m ";
            }
            else if (enemy->getX() == x && enemy->getY() == y)
            {
                std::cout << "\033[1;32m" << world[x][y][z] << "\033[0m ";
            }
            else
            {
                std::cout << world[x][y][z] << " ";
            }
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "+";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "--";
    }
    std::cout << "-+" << std::endl;
    std::string playerType;
    switch (player->getType())
    {
    case 1:
        playerType = "Sorting-Miner";
        break;
    case 2:
        playerType = "Tri-Miner";
        break;
    case 3:
        playerType = "AvgMiner";
        break;
    default:
        break;
    }
    std::string enemyType;
    switch (enemy->getType())
    {
    case 1:
        enemyType = "Sorting-Miner";
        break;
    case 2:
        enemyType = "Tri-Miner";
        break;
    case 3:
        enemyType = "AvgMiner";
        break;
    default:
        break;
    }

    std::cout << "\nPlayer 1 (" << playerType << ") Score: " << player->getScore() << std::endl;
    std::cout << "Ebenenwerte: ";
    for (int z = 0; z < height; z++)
    {
        std::cout << world[player->getX()][player->getY()][z] << " ";
    }
    std::cout << "\nPlayer 2 (" << enemyType << ") Score: " << enemy->getScore() << std::endl;
    std::cout << "Ebenenwerte: ";
    for (int z = 0; z < height; z++)
    {
        std::cout << world[enemy->getX()][enemy->getY()][z] << " ";
    }
}

void World::updateWorld(Miner *player, Miner *enemy)
{
    if (player->getType() == 1)
    {
        sort(world[player->getX()][player->getY()], true);
        player->setScore(player->getScore() + world[player->getX()][player->getY()][9]);
        world[player->getX()][player->getY()][9] = 0;
        for (int i = 9; i > 0; i--)
        {
            world[player->getX()][player->getY()][i] = world[player->getX()][player->getY()][i - 1];
        }
        world[player->getX()][player->getY()][0] = 0;
    }
    else if (player->getType() == 2)
    {
        player->setScore(player->getScore() + world[player->getX()][player->getY()][9] + world[player->getX()][player->getY()][8] + world[player->getX()][player->getY()][7]);
        world[player->getX()][player->getY()][9] = 0;
        world[player->getX()][player->getY()][8] = 0;
        world[player->getX()][player->getY()][7] = 0;
        for (int i = 9; i > 2; i--)
        {
            world[player->getX()][player->getY()][i] = world[player->getX()][player->getY()][i - 3];
        }
        world[player->getX()][player->getY()][0] = 0;
        world[player->getX()][player->getY()][1] = 0;
        world[player->getX()][player->getY()][2] = 0;
    }
    else if (player->getType() == 3)
    {
        player->setScore(player->getScore() + world[player->getX()][player->getY()][9]);
        world[player->getX()][player->getY()][9] = 0;
        for (int i = 9; i > 0; i--)
        {
            world[player->getX()][player->getY()][i] = world[player->getX()][player->getY()][i - 1];
        }
        world[player->getX()][player->getY()][0] = 0;
    }
    if (enemy->getType() == 1)
    {
        sort(world[enemy->getX()][enemy->getY()], true);
        enemy->setScore(enemy->getScore() + world[enemy->getX()][enemy->getY()][9]);
        world[enemy->getX()][enemy->getY()][9] = 0;
        for (int i = 9; i > 0; i--)
        {
            world[enemy->getX()][enemy->getY()][i] = world[enemy->getX()][enemy->getY()][i - 1];
        }
        world[enemy->getX()][enemy->getY()][0] = 0;
    }
    else if (enemy->getType() == 2)
    {
        enemy->setScore(enemy->getScore() + world[enemy->getX()][enemy->getY()][9] + world[enemy->getX()][enemy->getY()][8] + world[enemy->getX()][enemy->getY()][7]);
        world[enemy->getX()][enemy->getY()][9] = 0;
        world[enemy->getX()][enemy->getY()][8] = 0;
        world[enemy->getX()][enemy->getY()][7] = 0;
        for (int i = 9; i > 2; i--)
        {
            world[enemy->getX()][enemy->getY()][i] = world[enemy->getX()][enemy->getY()][i - 3];
        }
        world[enemy->getX()][enemy->getY()][0] = 0;
        world[enemy->getX()][enemy->getY()][1] = 0;
        world[enemy->getX()][enemy->getY()][2] = 0;
    }
    else if (enemy->getType() == 3)
    {
        enemy->setScore(enemy->getScore() + world[enemy->getX()][enemy->getY()][9]);
        world[enemy->getX()][enemy->getY()][9] = 0;
        for (int i = 9; i > 0; i--)
        {
            world[enemy->getX()][enemy->getY()][i] = world[enemy->getX()][enemy->getY()][i - 1];
        }
        world[enemy->getX()][enemy->getY()][0] = 0;
    }
}

World::~World()
{
    // dtor
}
