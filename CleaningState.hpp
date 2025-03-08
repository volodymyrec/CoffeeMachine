#ifndef CLEANINGSTATE_HPP
#define CLEANINGSTATE_HPP

#include "CoffeeMachineState.hpp"

class CoffeeMachine;

class CleaningState : public CoffeeMachineState {
public:
    CleaningState(CoffeeMachine* machine);
    void showMenu() override;
    void update() override;
    void receiveInput(int option) override;
private:
    CoffeeMachine* machine;
};

#endif
