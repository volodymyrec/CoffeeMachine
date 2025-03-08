#ifndef TEA_HPP
#define TEA_HPP

#include "DrinkProgram.hpp"

class Tea : public DrinkProgram {
public:
    Tea(CoffeeMachine& machine) : DrinkProgram(machine) {}
    virtual ~Tea() = default;
protected:
    virtual int getWaterTemperature() = 0;
};

#endif 
