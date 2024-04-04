#include "craft.h"
#include <chrono>
#include <ios>
#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <thread>

using std::cout;
using std::cin;

void ProcessDelay() {
    for (int i = 0; i <= 4; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << '.';
        cout.flush();
    }
}

void CraftPlanks(std::map<std::string, int> &inventory) {
    int wood_Ammount_in_inventory = inventory["Wood"];
    int choose_wood_ammount_to_make_plank = 0;
    int plankAmmount = 1;

    if (!(inventory["Wood"] <= 0)) {
        cout << "You have " << wood_Ammount_in_inventory << " ammount of Wood.\n";

        do {
            cout << "Enter the ammount of Wood to make planks : ";
            cin >> choose_wood_ammount_to_make_plank;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Invalid Input.\n";
                continue;
            }

            else if (choose_wood_ammount_to_make_plank > wood_Ammount_in_inventory) {
                continue;
            }

            else {
                break;
            }
        } while (true);

        //updating and adding plank to the inventory.
        plankAmmount = choose_wood_ammount_to_make_plank * 4;
        inventory["Plank"] = plankAmmount;

        //updating wood amount from the inventory.
        inventory["Wood"] = inventory["Wood"] - choose_wood_ammount_to_make_plank;
    }

    else {
        cout << "\nInsufficient ammount of Wood.\n";
    }
}

void CraftSticks(std::map<std::string, int> &inventory) {
    int plank_ammount_in_inventory = inventory["Plank"];
    int choose_stick_ammount_to_craft = 0;
    int stickAmmount = 1;

    if (inventory["Plank"] >= 2) {
        cout << "(1 Plank = 2 Sticks)\n";
        do {
            cout << "You have " << plank_ammount_in_inventory << " ammount of Plank.\n";
            cout << "Enter the ammount of sticks to craft : ";
            cin >> choose_stick_ammount_to_craft;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Invalid Input.\n\n";
                continue;
            }

            else if (choose_stick_ammount_to_craft <= 0 || choose_stick_ammount_to_craft / 2 > plank_ammount_in_inventory) {
                continue;
            }

            else {
                if (choose_stick_ammount_to_craft % 2 == 0) {
                    break;
                }

                else {
                    cout << "The amount of stick should be in Even Number.\n";
                }
            }
        } while (true);

        //crafting and adding sticks to the inventory.
        stickAmmount = choose_stick_ammount_to_craft;
        inventory["Stick"] = stickAmmount;

        //updating plank ammount from the inventory.
        inventory["Plank"] = inventory["Plank"] - choose_stick_ammount_to_craft / 2;
    }

    else {
        cout << "\nInsufficient ammount of Plank.\n";
    }

}

void CraftSword(std::map<std::string, int> &inventory) {
    int stone_required_to_craft_sword = 2;
    int stick_required_to_craft_sword = 1;

    int stone_in_inventory = inventory["Stone"];
    int stick_in_inventory = inventory["Stick"];
    int stone_sword_in_inventory = inventory["Sword"];

    cout << "\nCrafting Sword";
    cout.flush();

    if (stick_in_inventory >= 1 && stone_in_inventory >= 2 & inventory["Sword"] == 0) {
        ProcessDelay();

        cout << "You have Crafted a Sword.\n";
        cout.flush();

        inventory["Sword"] += 1;

        inventory["Stick"] -= stick_required_to_craft_sword;
        inventory["Stone"] -= stone_required_to_craft_sword;
    }

    else {
        if (inventory["Sword"] != 0) {
            cout << "\nYou already Own a Sword.\n";
        }

        else {
            cout << "\nInsufficient ammount of Requirements.\n";
        }
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));
}
//Crafting both axe and picaxe because the Requirements are same.
void CraftAxes(std::map<std::string, int> &inventory, const std::string itemName) {
    int Stone_in_inventory = inventory["Stone"];
    int stick_in_inventory = inventory["Stick"];

    int stick_required_to_craft_axes = 2;
    int stone_required_to_craft_axes = 3;

    if (Stone_in_inventory >= 3 && stick_in_inventory >= 2 && inventory[itemName] == 0) {
        cout << "\nCrafting " << itemName;
        cout.flush();

        ProcessDelay();
        
        cout << "You have Crafted an " << itemName << '\n';
        cout.flush();

        inventory[itemName] = 1;

        inventory["Stick"] -= stick_required_to_craft_axes;
        inventory["Stone"] -= stone_required_to_craft_axes;
    }

    else {
        if (itemName == "Axe" && inventory[itemName] != 0) {
            cout << "You already Own an " << itemName << '\n';
        }

        else if (itemName == "PicAxe" && inventory[itemName] != 0) {
            cout << "You already Own a " << itemName << '\n';
        }

        else {
            cout << "\nInsufficient amount of Requirements.\n";
        }
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

void CraftItems(std::map<std::string, int> &inventory) {
    bool running = true;
    int craftChoice = 0;

    do {
        do {
            cout << "\n1 - Wood Planks : [Requirements] - Wood\n2 - Sticks : [Requirements] - Planks\n3 - Sword : [Requirements] - Stick : 1, Stone : 2\n4 - Axe : [Requirements] - Stick : 2, Stone : 3\n5 - PicAxe : [Requirements] - Stick : 2, Stone : 3\n6 - Exit\nEnter : ";
            cin >> craftChoice;

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

        switch (craftChoice) {
            case 1:
                CraftPlanks(inventory);
                break;

            case 2:
                CraftSticks(inventory);
                break;

            case 3:
                CraftSword(inventory);
                break;

            case 4:
                CraftAxes(inventory, "Axe");
                break;

            case 5:
                CraftAxes(inventory, "PicAxe");
                break;

            case 6:
                running = false;
                break;

            default:
                cout << "Invalid Choice.\n\n";
                break;
        }
    } while (running);
}
