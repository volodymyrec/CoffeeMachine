#ifndef BLACKTEA_HPP
#define BLACKTEA_HPP

#include "Tea.hpp"

class BlackTea : public Tea {
public:
    BlackTea(CoffeeMachine& machine);
    void showInfo() override;
    DrinkProgramStatus prepare() override;
protected:
    int getWaterTemperature() override;
};

#endif 
