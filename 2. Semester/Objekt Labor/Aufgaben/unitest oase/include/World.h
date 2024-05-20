#ifndef WORLD_H
#define WORLD_H

class Player;
class Enemy;

class World
{
    public:
        void generateWorld();
        void displayWorld(Player* player, Enemy* enemy);
        void updateWorld(Player* player);

        char world[5][5];
        int relics = 0;
};

#endif // WORLD_H
