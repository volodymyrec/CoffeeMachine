#ifndef COFFEEMACHINESTATE_HPP
#define COFFEEMACHINESTATE_HPP

#include <iostream>

class CoffeeMachine; 

class CoffeeMachineState {
public:
    virtual ~CoffeeMachineState() = default;
    virtual void showMenu() = 0;
    virtual void update() = 0;
    virtual void receiveInput(int option) = 0;
};

#endif
