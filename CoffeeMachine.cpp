#include "CoffeeMachine.hpp"
#include "IdleState.hpp"
#include <algorithm>
#include <iostream>
#include "Espresso.hpp"
#include "Cappuccino.hpp"
#include "BlackTea.hpp"
#include "GreenTea.hpp"

CoffeeMachine::CoffeeMachine()
    : waterReservoir(),
      milkReservoir(),
      coffeeGrainsContainer(),
      currentState(new IdleState(this)),
      booted(true),
      usageCounter(0)
{
    initDefaultDrinks();
}

CoffeeMachine::~CoffeeMachine() {
    delete currentState;
}

void CoffeeMachine::setState(CoffeeMachineState* state) {
    delete currentState;
    currentState = state;
}

void CoffeeMachine::update() {
    currentState->update();
    if (++usageCounter >= CleanThreshold) {
        std::cout << "Machine requires cleaning after " << usageCounter << " uses.\n";
       
    }
}

void CoffeeMachine::receiveInput(int option) {
    currentState->receiveInput(option);
}

bool CoffeeMachine::checkWater(float amount) const {
    return waterReservoir.checkVolume(amount);
}

bool CoffeeMachine::checkMilk(float amount) const {
    return milkReservoir.checkVolume(amount) && !milkReservoir.isSpoiled();
}

bool CoffeeMachine::checkCoffeeGrains(float amount) const {
    return coffeeGrainsContainer.getVolume() >= amount;
}

void CoffeeMachine::useWater(float amount) {
    if (checkWater(amount))
        waterReservoir.use(amount);
}

void CoffeeMachine::useMilk(float amount) {
    if (checkMilk(amount))
        milkReservoir.use(amount);
}

void CoffeeMachine::useCoffeeGrains(float amount) {
    if (checkCoffeeGrains(amount))
        coffeeGrainsContainer.useGrains(amount);
}

void CoffeeMachine::clean() {
    coffeeGrainsContainer.cleanWaste();
    usageCounter = 0;
}

void CoffeeMachine::refillWater(float amount) {
    waterReservoir.refill(amount);
}

void CoffeeMachine::refillMilk(float amount) {
    milkReservoir.refill(amount);
}

void CoffeeMachine::refillCoffeeGrains(float amount) {
    coffeeGrainsContainer.refill(amount);
}

void CoffeeMachine::initDefaultDrinks() {
    drinkPrograms.clear();
    drinkPrograms.push_back(std::make_unique<Espresso>(*this));
    drinkPrograms.push_back(std::make_unique<Cappuccino>(*this));
    drinkPrograms.push_back(std::make_unique<BlackTea>(*this));
    drinkPrograms.push_back(std::make_unique<GreenTea>(*this));
}

void CoffeeMachine::addDrinkReceipt(std::unique_ptr<DrinkProgram> drink) {
    drinkPrograms.push_back(std::move(drink));
}

void CoffeeMachine::showMenu() {
    std::cout << "Available drinks:\n";
    for (size_t i = 0; i < drinkPrograms.size(); ++i) {
        std::cout << i + 1 << ". ";
        drinkPrograms[i]->showInfo();
        std::cout << "\n";
    }
}

void CoffeeMachine::makeDrink() {
    std::cout << "Select drink number: ";
    int choice;
    std::cin >> choice;
    if (choice < 1 || choice > static_cast<int>(drinkPrograms.size())) {
        std::cout << "Invalid selection.\n";
        return;
    }
    DrinkProgramStatus status = drinkPrograms[choice - 1]->prepare();
    if (status != DrinkProgramStatus::Success) {
        std::cout << "Failed to prepare drink. Error code: " << static_cast<int>(status) << "\n";
    } else {
        std::cout << "Enjoy your drink!\n";
    }
}

void CoffeeMachine::shutdown() {
    booted = false;
}

bool CoffeeMachine::isBooted() const {
    return booted;
}
