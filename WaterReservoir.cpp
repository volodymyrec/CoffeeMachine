#include "WaterReservoir.hpp"

WaterReservoir::WaterReservoir() : m_Volume(MaxVolume) {}

bool WaterReservoir::checkVolume(float amount) const {
    return m_Volume >= amount;
}

void WaterReservoir::use(float amount) {
    if(checkVolume(amount))
        m_Volume -= amount;
}

void WaterReservoir::refill(float amount) {
    m_Volume = std::min(m_Volume + amount, MaxVolume);
}

float WaterReservoir::getVolume() const {
    return m_Volume;
}

void WaterReservoir::showOperations() {
    std::cout << "\n--- Current water level: " << getVolume() << "l out of " << MaxVolume << "l max ---\n";
    std::cout << "1. Empty reservoir\n";
    std::cout << "2. Fill up with water\n";
    std::cout << "3. Back to main\n";
}

void WaterReservoir::receiveInput() {
    std::cout << "Choice: ";
    std::cin >> m_Operation;
}

void WaterReservoir::update() {
    switch (m_Operation)
    {
    case 1:
        m_Volume = 0.0f;
        break;
    case 2:
    {
        float newVolume = 0.0f;
        std::cout << "Filling... How much? (Max: " << MaxVolume << "l): ";
        std::cin >> newVolume;
        m_Volume = std::min(newVolume, MaxVolume);
        break;
    }
    case 3:
    default:
        break;
    }
}
