#ifndef WORLD_H
#define WORLD_H

#include <vector>

class Miner;

class World
{
public:
    World(int gamemode);
    virtual ~World();

    void printWorld(Miner *player, Miner *enemy);
    void updateWorld(Miner *player, Miner *enemy);

private:
    int gamemode;
    std::vector<std::vector<std::vector<int>>> world;
    const int length = 5;
    const int width = 5;
    const int height = 10;
};

#endif // WORLD_H
