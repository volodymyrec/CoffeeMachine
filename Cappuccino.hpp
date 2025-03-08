#ifndef CAPPUCCINO_HPP
#define CAPPUCCINO_HPP

#include "Coffee.hpp"

class Cappuccino : public Coffee {
public:
    Cappuccino(CoffeeMachine& machine);
    void showInfo() override;
    DrinkProgramStatus prepare() override;
};

#endif
