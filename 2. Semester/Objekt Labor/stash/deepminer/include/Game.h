#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();

    void showIntro();
    void gamemode();

    virtual ~Game();

protected:
private:
    int gamemode;
};

#endif // GAME_H
