#include "IdleState.hpp"
#include "CoffeeMachine.hpp"
#include "CleaningState.hpp"
#include "SleepState.hpp"

IdleState::IdleState(CoffeeMachine* machine) : machine(machine) {}

void IdleState::showMenu() {
    std::cout << "\n=== Coffee Machine Menu ===\n";
    std::cout << "1. Make a drink\n";
    std::cout << "2. Clean machine\n";
    std::cout << "3. Sleep mode\n";
    std::cout << "4. Exit\n";
    std::cout << "---------------------------\n";
    std::cout << "Available drinks:\n";
    machine->showMenu();
}

void IdleState::update() {
  
}

void IdleState::receiveInput(int option) {
    switch(option) {
        case 1:
            machine->makeDrink();
            break;
        case 2:
            machine->setState(new CleaningState(machine));
            break;
        case 3:
            machine->setState(new SleepState(machine));
            break;
        case 4:
            machine->shutdown();
            break;
        default:
            std::cout << "Invalid option!\n";
            break;
    }
}
