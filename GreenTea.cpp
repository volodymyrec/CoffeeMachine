#include "GreenTea.hpp"
#include "CoffeeMachine.hpp"

const float GreenTeaWaterVolume = 0.2f;

GreenTea::GreenTea(CoffeeMachine& machine) : Tea(machine) {}

void GreenTea::showInfo() {
    std::cout << "Green Tea";
}

DrinkProgramStatus GreenTea::prepare() {
    if (!machine.checkWater(GreenTeaWaterVolume))
        return DrinkProgramStatus::LowWater;
    
    machine.useWater(GreenTeaWaterVolume);
    
    std::cout << "Steeping Green Tea at " << getWaterTemperature() << "°C...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Green Tea is ready!\n";
    return DrinkProgramStatus::Success;
}

int GreenTea::getWaterTemperature() {
    return 80;
}
