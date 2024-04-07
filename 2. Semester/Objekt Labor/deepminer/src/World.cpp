#include "World.h"
#include "Miner.h"

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

void World::status(Miner &player, Miner &cpu)
{
    std::cout << "Player: " << player.getX() << " " << player.getY() << " Level: " << player.getZ() << std::endl;
    std::cout << "CPU: " << cpu.getX() << " " << cpu.getY() << " Level: " << cpu.getZ() << std::endl;
}

void World::printWorld()
{
    for (int z = 0; z < height; z++)
    {
        std::cout << "Level " << z + 1 << std::endl;
        for (int y = 0; y < width; y++)
        {
            for (int x = 0; x < length; x++)
            {
                std::cout << world[x][y][z] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void World::updateWorld(Miner &player, Miner &cpu)
{
    world[player.getX()][player.getY()][player.getZ()] = 0;
    world[cpu.getX()][cpu.getY()][cpu.getZ()] = 0;
}

World::~World()
{
    // dtor
}
