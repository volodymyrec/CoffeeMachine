#include "BlackTea.hpp"
#include "CoffeeMachine.hpp"

const float BlackTeaWaterVolume = 0.2f;

BlackTea::BlackTea(CoffeeMachine& machine) : Tea(machine) {}

void BlackTea::showInfo() {
    std::cout << "Black Tea";
}

DrinkProgramStatus BlackTea::prepare() {
    if (!machine.checkWater(BlackTeaWaterVolume))
        return DrinkProgramStatus::LowWater;
    
    machine.useWater(BlackTeaWaterVolume);
    
    std::cout << "Steeping Black Tea at " << getWaterTemperature() << "°C...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Black Tea is ready!\n";
    return DrinkProgramStatus::Success;
}

int BlackTea::getWaterTemperature() {
    return 95;
}
