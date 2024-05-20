#ifndef ENEMY_H
#define ENEMY_H

class World;
class Player;

class Enemy
{
    public:
        Enemy();

        void renderEnemy();
        void enemyMove();
        void resetEnemy();

        int x;
        int y;
};

#endif // ENEMY_H
