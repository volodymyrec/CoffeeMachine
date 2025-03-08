#ifndef COFFEE_HPP
#define COFFEE_HPP

#include "DrinkProgram.hpp"

class Coffee : public DrinkProgram {
public:
    Coffee(CoffeeMachine& machine) : DrinkProgram(machine) {}
    virtual ~Coffee() = default;
};

#endif 
