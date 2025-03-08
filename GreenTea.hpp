#ifndef GREENTEA_HPP
#define GREENTEA_HPP

#include "Tea.hpp"

class GreenTea : public Tea {
public:
    GreenTea(CoffeeMachine& machine);
    void showInfo() override;
    DrinkProgramStatus prepare() override;
protected:
    int getWaterTemperature() override;
};

#endif 
