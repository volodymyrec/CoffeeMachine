#ifndef SLEEPSTATE_HPP
#define SLEEPSTATE_HPP

#include "CoffeeMachineState.hpp"

class CoffeeMachine;

class SleepState : public CoffeeMachineState {
public:
    SleepState(CoffeeMachine* machine);
    void showMenu() override;
    void update() override;
    void receiveInput(int option) override;
private:
    CoffeeMachine* machine;
};

#endif
