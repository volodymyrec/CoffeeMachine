#include "CoffeeGrainsContainer.hpp"

CoffeeGrainsContainer::CoffeeGrainsContainer() : m_Volume(1.0f), m_Waste(0) {}

bool CoffeeGrainsContainer::hasGrains(float amount) const {
    return m_Volume >= amount;
}

void CoffeeGrainsContainer::useGrains(float amount) {
    if (hasGrains(amount)) {
        m_Volume -= amount;
        m_Waste += amount;
    }
}

void CoffeeGrainsContainer::grindGrains(float amount) {
    if (hasGrains(amount)) {
    }
}

void CoffeeGrainsContainer::refill(float amount) {
    m_Volume = std::min(m_Volume + amount, MaxVolume);
}

void CoffeeGrainsContainer::cleanWaste() {
    m_Waste = 0;
}

float CoffeeGrainsContainer::getVolume() const {
    return m_Volume;
}
