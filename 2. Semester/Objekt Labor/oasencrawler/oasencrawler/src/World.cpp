#include <iostream>

#include "Player.h"
#include "World.h"
#include "Enemy.h"

void World::generateWorld()
{
    for(int y = 0; y < 5; y++)
    {
        for(int x = 0; x < 5; x++)
        {
            int randomNum = rand() % 10;
            if(randomNum < 4)
            {
                world[y][x] = '_';
            }
            else if(randomNum < 8)
            {
                world[y][x] = 'G';
            }
            else if(randomNum < 9)
            {
                world[y][x] = 'B';
            }
            else
            {
                world[y][x] = 'R';
                relics++;
            }
        }
    }
    if(relics == 0)
    {
        generateWorld();
    }
}

void World::displayWorld(Player* player, Enemy* enemy)
{
    for(int y = 0; y < 5; y++)
    {
        for(int x = 0; x < 5; x++)
        {
            if(player->x == x && player->y == y)
            {
                player->render();
            }
            else if(enemy->x == x && enemy->y == y)
            {
                enemy->renderEnemy();
            }
            else
            {
                std::cout << world[y][x] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "\n";
}

void World::updateWorld(Player* player)
{
    world[player->y][player->x] = '_';
}
