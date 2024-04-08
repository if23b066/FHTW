#include "World.h"
#include "Miner.h"

#include <iostream>

int main()
{
    std::cout << "Welcome to DeepMiner!" << std::endl;
    std::cout << "\nYou are a miner in a deep mine.\nYour goal is to collect as many valuable minerals as possible." << std::endl;
    std::cout << "\n";
    system("pause");
    system("cls");
    std::cout << "Choose your Mode:" << std::endl;
    std::cout << "\nPlayer vs CPU  (1) \nCPU vs CPU (2)" << std::endl;
    std::cout << "\nEnter your choice: ";

    int gamemode;
    std::cin >> gamemode;

    World world(gamemode);
    while (gamemode < 1 || gamemode > 2)
    {
        std::cout << "Invalid choice! Please enter 1 or 2!" << std::endl;
    }

    system("cls");
    if (gamemode == 1)
    {
        std::cout << "Choose your Miner:" << std::endl;
        std::cout << "\n(1) Sorting-Miner \n(2) Tri-Miner \n(3) AvgMiner" << std::endl;
        int miner;
        std::cout << "\nEnter your choice: ";
        std::cin >> miner;
        while (miner < 1 || miner > 3)
        {
            std::cout << "Invalid Input. Please enter 1, 2, or 3." << std::endl;
            std::cin >> miner;
        }
        Miner *player = new Miner(0, 0, 0, miner);
        Miner *enemy = new Miner(4, 4, 0, rand() % 3 + 1);
        world.printWorld(player, enemy);
        char input;
        while (true)
        {
            std::cout << "\n";
            std::cout << "\nW (Up), A (Left), S (Down), D (Right), F (Stand Still), X (End)" << std::endl;
            std::cin >> input;
            if (input == 'x')
            {
                break;
            }
            if (player->move(input) == 1)
            {
                std::cout << "Invalid Input" << std::endl;
            }
            enemy->randomMove();
            world.mineField(player, enemy);
            world.updateWorld();
            world.printWorld(player, enemy);
        }
    }
    else if (gamemode == 2)
    {
        Miner *player = new Miner(0, 0, 0, rand() % 3 + 1);
        Miner *enemy = new Miner(4, 4, 0, rand() % 3 + 1);
        world.printWorld(player, enemy);
        char input = ' ';
        while (true)
        {
            std::cout << "\n";
            system("pause");
            if (input == 'x')
            {
                break;
            }
            player->randomMove();
            enemy->randomMove();
            world.mineField(player, enemy);
            world.updateWorld();
            world.printWorld(player, enemy);
        }
    }

    return 0;
}
