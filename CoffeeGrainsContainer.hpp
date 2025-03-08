#ifndef COFFEEGRAINSCONTAINER_HPP
#define COFFEEGRAINSCONTAINER_HPP

#include <algorithm>

class CoffeeGrainsContainer {
public:
    CoffeeGrainsContainer();
    bool hasGrains(float amount) const;
    void useGrains(float amount);
    void grindGrains(float amount); 
    void refill(float amount);
    void cleanWaste();
    float getVolume() const;
private:
    float m_Volume;
    float m_Waste;
    static constexpr float MaxVolume = 1.0f;
};

#endif
