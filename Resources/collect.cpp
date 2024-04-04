#include "collect.h"
#include <chrono>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <ios>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <thread>

using std::cout;
using std::cin;

void CollectTheItem(const std::string &itemName, int &itemAmmount) {
    if (itemName == "Wood") {
        cout << "\nCutting Trees";
        cout.flush();
    }

    if (itemName == "Stone") {
        cout << "\nMining Stones";
        cout.flush();
    }

    for (int i = 0; i <= 4; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << '.';
        cout.flush();
    }

    itemAmmount = (rand() % 8) + 1;

    cout << itemName << " is collected, Ammount : " << itemAmmount << '\n';
    cout.flush();

    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << '\n';
}

void FillInventory(std::map<std::string, int> &inventory, const std::string &itemName, const int &itemAmmount) {
    int tempAmmount = inventory[itemName];
    inventory[itemName] = tempAmmount + itemAmmount;
}

void CollectResources(std::map<std::string, int> &inventory) {
    srand(time(NULL));
    bool running = true;
    int collectChoice = 0;

    std::string resourceName = "none";
    int resourceAmmount = 0;

    do {
        do {
            cout << "1 - Collect Woods\n2 - Collect Stones\n3 - Cancel\nEnter : ";
            cin >> collectChoice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Invalid Input.\n\n";
                continue;
            }

            else {
                break;
            }
        } while (true);

        std::string itemName;
        int itemAmmount = 0;

        switch (collectChoice) {
            case 1:
                itemName = "Wood";
                CollectTheItem(itemName, itemAmmount);
                FillInventory(inventory, itemName, itemAmmount);
                break;

            case 2:
                itemName = "Stone";
                CollectTheItem(itemName, itemAmmount);
                FillInventory(inventory, itemName, itemAmmount);
                break;

            case 3:
                running = false;
                break;

            default:
                cout << "Invalid Choice.\n\n";
                break;
        }

        cin.clear();

    } while (collectChoice != 3);
}
