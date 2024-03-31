#include <iostream>

#include "Game.h"
#include "Fighter.h"

Game::Game()
{
    // ctor
}

void Game::printIntro()
{
    std::cout << "Welcome to Fight Club!" << std::endl;
    std::cout << "You are about to enter a world of pain and suffering." << std::endl;
    std::cout << "You will be fighting against the most fearsome opponents." << std::endl;
    std::cout << "You will have to use all your strength and cunning to survive." << std::endl;

    std::cout << "\nChoose your gamemode: Singleplayer (1) or Multiplayer (2)?" << std::endl;
    do
    {
        std::cin >> gamemode;
        if (gamemode != 1 && gamemode != 2)
        {
            std::cout << "Invalid input!" << std::endl;
        }
    } while (gamemode != 1 && gamemode != 2);
    system("cls");
}

void Game::showTutorial()
{
    std::cout << "Welcome to the tutorial!" << std::endl;
    std::cout << "\nEach fighter has 3 stats: Attack, Defense and Agility." << std::endl;
    std::cout << "Attack determines how much damage you deal to your opponent." << std::endl;
    std::cout << "Defense determines how much damage you take from your opponent." << std::endl;
    std::cout << "Agility determines how likely you are to dodge an attack." << std::endl;

    if (gamemode == 1)
    {
        std::cout << "\nChoose your fighter: " << std::endl;

        std::cout << "\n1. Mike Tyson (1): high attack, low defense, medium agility." << std::endl;
        std::cout << "2. Tyson Fury (2): medium attack, high defense, low agility." << std::endl;
        std::cout << "3. Muhammad Ali (3): low attack, medium defense, high agility." << std::endl;
    }

    if (gamemode == 2)
    {
        std::cout << "\nPlayer 1, choose your fighter: " << std::endl;

        std::cout << "\n1. Mike Tyson (1): high attack, low defense, medium agility." << std::endl;
        std::cout << "2. Tyson Fury (2): medium attack, high defense, low agility." << std::endl;
        std::cout << "3. Muhammad Ali (3): low attack, medium defense, high agility." << std::endl;

        std::cout << "\nPlayer 2, choose your fighter: " << std::endl;

        std::cout << "\n1. Mike Tyson (1): high attack, low defense, medium agility." << std::endl;
        std::cout << "2. Tyson Fury (2): medium attack, high defense, low agility." << std::endl;
        std::cout << "3. Muhammad Ali (3): low attack, medium defense, high agility." << std::endl;
    }
}

Game::~Game()
{
    // dtor
}
