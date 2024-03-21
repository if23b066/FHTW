#include <iostream>

#include "Menu.h"
#include "Stock.h"
#include "HashTable.h"

int main()
{
    Menu *menu = new Menu();
    int choice = 0;

    do
    {
        menu->displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            // ADD: Aktie hinzufügen
            break;
        case 2:
            // DEL: Aktie löschen
            break;
        case 3:
            // IMPORT: Kurswerte importieren
            break;
        case 4:
            // SEARCH: Aktie suchen
            break;
        case 5:
            // PLOT: Kursverlauf plotten
            break;
        case 6:
            // SAVE: Hashtabelle speichern
            break;
        case 7:
            // LOAD: Hashtabelle laden
            break;
        case 8:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (choice != 8);

    delete menu;
    return 0;
}
