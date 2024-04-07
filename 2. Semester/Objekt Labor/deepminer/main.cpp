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

    if (gamemode == 1)
    {
        Miner player(0, 0, 0, 0, 0);
        Miner cpu(4, 4, 0, 0, 1);

        world.printWorld();
        world.status(player, cpu);

        char direction;
        do
        {
            std::cout << "\n(w) Up (s) Down (a) Left (d) Right" << std::endl;
            std::cout << "Enter your move: ";
            std::cin >> direction;
            player.move(direction);
            cpu.randomMove(direction);

            system("cls");
            world.updateWorld(player, cpu);
            world.printWorld();
            world.status(player, cpu);
        } while (direction != 'x' && direction != 'X');
    }

    return 0;
}
