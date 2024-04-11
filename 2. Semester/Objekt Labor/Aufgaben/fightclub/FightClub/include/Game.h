#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();

    void printIntro();
    void showTutorial();

    virtual ~Game();

private:
    int gamemode;
};

#endif // GAME_H
