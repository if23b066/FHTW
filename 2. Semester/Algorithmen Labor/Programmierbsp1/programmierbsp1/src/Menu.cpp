#include <iostream>

#include "Menu.h"

Menu::Menu()
{
    // ctor
}

void Menu::displayMenu()
{
    std::cout << "1. ADD\n"
              << "2. DEL\n"
              << "3. IMPORT\n"
              << "4. SEARCH\n"
              << "5. PLOT\n"
              << "6. SAVE <filename>\n"
              << "7. LOAD <filename>\n"
              << "8. QUIT\n";
}

Menu::~Menu()
{
    // dtor
}
