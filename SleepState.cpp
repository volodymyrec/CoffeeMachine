#include "SleepState.hpp"
#include "CoffeeMachine.hpp"
#include "IdleState.hpp"

SleepState::SleepState(CoffeeMachine* machine) : machine(machine) {}

void SleepState::showMenu() {
    std::cout << "\nMachine is in sleep mode. Press any key to wake up.\n";
}

void SleepState::update() {
}

void SleepState::receiveInput(int option) {
    std::cout << "Waking up machine...\n";
    machine->setState(new IdleState(machine));
}
