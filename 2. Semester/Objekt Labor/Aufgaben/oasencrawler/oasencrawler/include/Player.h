#ifndef PLAYER_H
#define PLAYER_H

class World;
class Enemy;

class Player
{
    public:
        Player(int x, int y);

        void move(char direction);
        void render();
        void activeField(World* world, Enemy* enemy);
        void resetPlayer();

        int x;
        int y;
        char direction;
        int colRelics = 0;
        int hp = 5;
        int difficulty = 1;
};

#endif // PLAYER_H
