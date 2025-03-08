#ifndef COFFEEMACHINE_HPP
#define COFFEEMACHINE_HPP

#include <vector>
#include <memory>
#include "DrinkProgram.hpp"
#include "WaterReservoir.hpp"
#include "MilkReservoir.hpp"
#include "CoffeeGrainsContainer.hpp"
#include "CoffeeMachineState.hpp"

class CoffeeMachine {
public:
    CoffeeMachine();
    ~CoffeeMachine();
    void setState(CoffeeMachineState* state);
    void update();
    void receiveInput(int option);
    bool checkWater(float amount) const;
    bool checkMilk(float amount) const;
    bool checkCoffeeGrains(float amount) const;
    void useWater(float amount);
    void useMilk(float amount);
    void useCoffeeGrains(float amount);
    void clean();
    void refillWater(float amount);
    void refillMilk(float amount);
    void refillCoffeeGrains(float amount);
    
    void shutdown();
    bool isBooted() const;
    
    void initDefaultDrinks();
    void addDrinkReceipt(std::unique_ptr<DrinkProgram> drink);
    void showMenu();
    void makeDrink();
    
    WaterReservoir waterReservoir;
    MilkReservoir milkReservoir;
    CoffeeGrainsContainer coffeeGrainsContainer;
private:
    CoffeeMachineState* currentState;
    std::vector<std::unique_ptr<DrinkProgram>> drinkPrograms;
    bool booted;
    int usageCounter;
    static const int CleanThreshold = 5;
};

#endif
