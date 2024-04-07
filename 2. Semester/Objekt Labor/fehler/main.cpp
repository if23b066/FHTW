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
    std::cout << "or quit the game (3)" << std::endl;
    std::cout << "\nEnter your choice: ";

    int gamemode;
    std::cin >> gamemode;
    do
    {
        switch (gamemode)
        {
        case 1:
            system("cls");
            break;
        case 2:
            system("cls");
            break;
        case 3:
            system("cls");
            std::cout << "Goodbye! Thank you for playing (or not)!" << std::endl;
            break;
        default:
            system("cls");
            break;
        }
    } while (gamemode != 3);

    return 0;
}
