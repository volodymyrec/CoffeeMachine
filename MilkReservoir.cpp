#include "MilkReservoir.hpp"
#include <algorithm>

MilkReservoir::MilkReservoir() : m_Volume(0), m_Spoiled(false) {}

bool MilkReservoir::checkVolume(float amount) const {
    return m_Volume >= amount;
}

void MilkReservoir::use(float amount) {
    if (checkVolume(amount))
        m_Volume -= amount;
}

void MilkReservoir::refill(float amount) {
    m_Volume = amount;
    m_Spoiled = false;
    lastRefillTime = std::chrono::steady_clock::now();
}

float MilkReservoir::getVolume() const {
    return m_Volume;
}

bool MilkReservoir::isSpoiled() const {
    return m_Spoiled;
}

void MilkReservoir::update() {
    auto now = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::hours>(now - lastRefillTime).count() > 5)
    {
        m_Spoiled = true;
    }
}
