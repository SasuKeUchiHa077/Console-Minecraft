#include "displayInv.h"
#include <iostream>
#include <string>

using std::cout;

void DisplayInv(std::map<std::string, int> &inventory) {
    cout << '\n';

    if (inventory.empty()) {
        cout << "Inventory is Empty.\n\n";
        return;
    }

    int i = 0;

    cout << "Your Inventory--------------------------\n";

    for (const auto &iterator : inventory) {
        cout << i + 1 << "] " << iterator.first << ", Ammount : " << iterator.second << '\n';
        i++;
    }

    cout << '\n';
}
