#include "CleaningState.hpp"
#include "CoffeeMachine.hpp"
#include "IdleState.hpp"

CleaningState::CleaningState(CoffeeMachine* machine) : machine(machine) {}

void CleaningState::showMenu() {
    std::cout << "\nCleaning machine...\n";
}

void CleaningState::update() {
    machine->clean();
    std::cout << "Machine cleaned. Returning to idle state.\n";
    machine->setState(new IdleState(machine));
}

void CleaningState::receiveInput(int option) {

}
