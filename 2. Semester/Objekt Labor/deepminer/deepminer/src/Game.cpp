#include <iostream>

#include "Game.h"

Game::Game()
{
    // ctor
}

void Game::showIntro()
{
    std::cout << "Welcome to DeepMiner!" << std::endl;
    std::cout << "\nYou are a miner in a deep mine.\n Your goal is to collect as many valuable minerals as possible." << std::endl;
    system("pause");
    std::cout << "Choose your Mode: \nPlayer vs CPU  (1) \nCPU vs CPU (2)" << std::endl;
}

void Game::gamemode()
{
    std::cin >> gamemode;
    switch (gamemode)
    {
    case 1:
        system("cls");
        std::cout << "Player vs CPU" << std::endl;
        break;
    case 2:
        system("cls");
        std::cout << "CPU vs CPU" << std::endl;
        break;
    default:
        system("cls");
        std::cout << "Invalid Input" << std::endl;
    }
}

void Game::playerVsCPU()
{
}

void Game::CPUvsCPU()
{
}

Game::~Game()
{
    // dtor
}
