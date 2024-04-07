#ifndef WORLD_H
#define WORLD_H

#include <vector>

class Miner;

class World
{
public:
    World(int gamemode);
    virtual ~World();

    void status(Miner &player, Miner &cpu);
    void printWorld();
    void updateWorld(Miner &player, Miner &cpu);

private:
    int gamemode;
    std::vector<std::vector<std::vector<int>>> world;
    const int length = 5;
    const int width = 5;
    const int height = 10;
};

#endif // WORLD_H
