#ifndef DRINKPROGRAM_HPP
#define DRINKPROGRAM_HPP

#include <iostream>
#include <chrono>
#include <thread>

enum class DrinkProgramStatus {
    Success,
    LowWater,
    LowMilk,
    LowCoffee,
    Error
};

class CoffeeMachine; 

class DrinkProgram {
public:
    DrinkProgram(CoffeeMachine& machine) : machine(machine) {}
    virtual ~DrinkProgram() = default;
    virtual void showInfo() = 0;
    virtual DrinkProgramStatus prepare() = 0;
protected:
    CoffeeMachine& machine;
};

#endif 
