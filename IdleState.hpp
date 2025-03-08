#ifndef IDLESTATE_HPP
#define IDLESTATE_HPP

#include "CoffeeMachineState.hpp"

class CoffeeMachine;

class IdleState : public CoffeeMachineState {
public:
    IdleState(CoffeeMachine* machine);
    void showMenu() override;
    void update() override;
    void receiveInput(int option) override;
private:
    CoffeeMachine* machine;
};

#endif 
