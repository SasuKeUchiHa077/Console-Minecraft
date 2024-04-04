#include <cctype>
#include "Resources/collect.h"
#include "Resources/craft.h"
#include "Resources/displayInv.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::cin;

void SaveProgress(const std::map<std::string, int> &inventory) {
    std::ofstream saveProgress;
    saveProgress.open("Resources/SaveProgress/progress.txt");

    std::string itemName;

    if (saveProgress.is_open()) {
        for (const auto &iterator : inventory) {
            saveProgress << iterator.first << ' ' << iterator.second << '\n';            
        }
        saveProgress.close();
    }
}

void LoadProgress(std::map<std::string, int> &inventory) {
    std::string itemName_temp;
    int itemAmmount_temp = 0;

    std::ifstream loadProgress;
    loadProgress.open("Resources/SaveProgress/progress.txt");

    if (loadProgress.is_open()) {
        while (loadProgress >> itemName_temp >> itemAmmount_temp) {
            inventory[itemName_temp] = itemAmmount_temp;
        }
        loadProgress.close();
    }
}

int main (int argc, char *argv[]) {
    char playerChoice = 'n';
    bool running = true;

    //inventory
    std::map<std::string, int> inventory;

    LoadProgress(inventory);

    do {
        cout << "[I] - Inventory\n[C] - Craft\n[R] - Collect Resources\n[X] - Exit\nEnter : ";

        cin >> playerChoice;

        playerChoice = toupper(playerChoice);

        switch (playerChoice) {
            case 'I':
                DisplayInv(inventory);
                break;

            case 'C':
                CraftItems(inventory);
                SaveProgress(inventory);
                break;

            case 'R':
                CollectResources(inventory);
                SaveProgress(inventory);
                break;

            case 'X':
                running = false;
                break;

            default:
                cout << "Invalid Choice.\n\n";
                break;
        }
    } while (running);
    return 0;
}
