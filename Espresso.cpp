#include "Espresso.hpp"
#include "CoffeeMachine.hpp"

const float EspressoWaterVolume = 0.05f;
const float EspressoCoffeeGrams = 0.01f; 

Espresso::Espresso(CoffeeMachine& machine) : Coffee(machine) {}

void Espresso::showInfo() {
    std::cout << "Espresso";
}

DrinkProgramStatus Espresso::prepare() {
    if (!machine.checkWater(EspressoWaterVolume))
        return DrinkProgramStatus::LowWater;
    if (!machine.checkCoffeeGrains(EspressoCoffeeGrams))
        return DrinkProgramStatus::LowCoffee;

    machine.useWater(EspressoWaterVolume);
    machine.useCoffeeGrains(EspressoCoffeeGrams);
    
    std::cout << "Brewing Espresso...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Espresso is ready!\n";
    return DrinkProgramStatus::Success;
}
