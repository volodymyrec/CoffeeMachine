#ifndef ESPRESSO_HPP
#define ESPRESSO_HPP

#include "Coffee.hpp"

class Espresso : public Coffee {
public:
    Espresso(CoffeeMachine& machine);
    void showInfo() override;
    DrinkProgramStatus prepare() override;
};

#endif 
