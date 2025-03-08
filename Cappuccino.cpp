#include "Cappuccino.hpp"
#include "CoffeeMachine.hpp"

const float CappuccinoWaterVolume = 0.05f;
const float CappuccinoCoffeeGrams = 0.01f;
const float CappuccinoMilkVolume = 0.03f;

Cappuccino::Cappuccino(CoffeeMachine& machine) : Coffee(machine) {}

void Cappuccino::showInfo() {
    std::cout << "Cappuccino";
}

DrinkProgramStatus Cappuccino::prepare() {
    if (!machine.checkWater(CappuccinoWaterVolume))
        return DrinkProgramStatus::LowWater;
    if (!machine.checkCoffeeGrains(CappuccinoCoffeeGrams))
        return DrinkProgramStatus::LowCoffee;
    if (!machine.checkMilk(CappuccinoMilkVolume))
        return DrinkProgramStatus::LowMilk;
    
    machine.useWater(CappuccinoWaterVolume);
    machine.useCoffeeGrains(CappuccinoCoffeeGrams);
    machine.useMilk(CappuccinoMilkVolume);
    
    std::cout << "Brewing Cappuccino...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Cappuccino is ready!\n";
    return DrinkProgramStatus::Success;
}
