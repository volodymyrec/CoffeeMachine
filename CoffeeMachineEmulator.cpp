#include "CoffeeMachine.hpp"
#include <iostream>

int main() {
    CoffeeMachine machine;
    while (machine.isBooted()) {
        machine.showMenu();
        int option;
        std::cout << "Enter option: ";
        std::cin >> option;
        machine.receiveInput(option);
        machine.update();
    }
    std::cout << "Coffee Machine is shutting down.\n";
    return 0;
}
