#include <iostream>

#include "Game.h"

int main()
{
    Game *game = new Game();

    game->showIntro();
    game->gamemode();

    delete game;
    return 0;
}
