#include <iostream>

#include "Fighter.h"
#include "Game.h"

int main()
{
    Game *gameStart = new Game;
    gameStart->printIntro();
    gameStart->showTutorial();

    delete gameStart;
    return 0;
}
