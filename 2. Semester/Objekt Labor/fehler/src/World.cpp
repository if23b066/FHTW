#include "World.h"

World::World()
{
    // ctor
}

void World::generateWorld()
{
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            int randomNum = rand() % 10;
            if (randomNum < 4)
            {
                world[y][x] = '_';
            }
            else if (randomNum < 8)
            {
                world[y][x] = 'G';
            }
            else if (randomNum < 9)
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
    if (relics == 0)
    {
        generateWorld();
    }
}

World::~World()
{
    // dtor
}
