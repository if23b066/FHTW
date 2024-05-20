/*
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Player.h"
#include "World.h"
#include "Enemy.h"

int main()
{
    srand(time(NULL));
    std::cout << "Oasencrawler\n\n";
    std::cout << "W/A/S/D + Enter um dich zu Bewegen\n\n";
    std::cout << "'x' => Spieler\n";
    std::cout << "'_' => Leeres Feld\n";
    std::cout << "'#' => Gegner\n";
    std::cout << "'G' => Gefahr (-1HP)\n";
    std::cout << "'B' => Heilbrunnen (+1HP)\n";
    std::cout << "'R' => Relikte\n\n";
    std::cout << "Dein Ziel: Sammle alle Relikte um weiterzukommen!\n\n";

    Player* player = new Player(0, 0);
    World* world = new World;
    Enemy* enemy = new Enemy();

    std::cout << "Derzeitiger Schwierigkeitsgrad: " << player->difficulty << "/5\n" << std::endl;
    world->generateWorld();
    world->displayWorld(player, enemy);

    char input;
    while (true)
    {
        std::cin >> input;
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        player->move(input);
        enemy->enemyMove();
        player->activeField(world, enemy);
        world->displayWorld(player, enemy);
        world->updateWorld(player);
        std::cout << "\nHP: (" << player->hp << "/5)\n" << std::endl;

        if(player->hp == 0)
        {
            std::cout << "Du hast verloren, GG!" << std::endl;
            break;
        }
        if(world->relics == 0)
        {
            std::cout << "Du hast alle Relikte gesammelt, GG!\n" << std::endl;
            if(player->difficulty == 5)
            {
                std::cout << "Du hast das Spiel durchgespielt!" << std::endl;
                break;
            }
            else
            {
                std::cout << "Ein neues Spielfeld wird generiert...\n" << std::endl;
                player->difficulty++;
                std::cout << "Der Schwierigkeitsgrad hat sich erhoeht!\n" << std::endl;
                std::cout << "Derzeitiger Schwierigkeitsgrad: " << player->difficulty << "/5\n" << std::endl;
                player->resetPlayer();
                world->generateWorld();
                world->displayWorld(player, enemy);
                player->hp = 5;
            }
        }
    }

    delete enemy;
    delete player;
    delete world;
    return 0;
}
*/
