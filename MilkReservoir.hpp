#ifndef MILKRESERVOIR_HPP
#define MILKRESERVOIR_HPP

#include "Reservoir.hpp"
#include <chrono>

class MilkReservoir : public Reservoir {
public:
    MilkReservoir();
    bool checkVolume(float amount) const override;
    void use(float amount) override;
    void refill(float amount) override;
    float getVolume() const override;
    bool isSpoiled() const;
    void update();
private:
    float m_Volume;
    bool m_Spoiled;
    std::chrono::steady_clock::time_point lastRefillTime;
};

#endif 
