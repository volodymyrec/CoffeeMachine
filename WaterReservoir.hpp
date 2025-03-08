#ifndef WATERRESERVOIR_HPP
#define WATERRESERVOIR_HPP

#include "Reservoir.hpp"
#include <iostream>
#include <algorithm>

class WaterReservoir : public Reservoir {
public:
    WaterReservoir();
    bool checkVolume(float amount) const override;
    void use(float amount) override;
    void refill(float amount) override;
    float getVolume() const override;
    void showOperations();
    void receiveInput();
    void update();
private:
    float m_Volume;
    static constexpr float MaxVolume = 2.0f;
    int m_Operation = 0;
};

#endif
