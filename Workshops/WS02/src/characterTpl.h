#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H

#include "character.h"
#include <iostream>

namespace seneca {

template<typename T>
class CharacterTpl : public Character {
private:
    T m_health;
    int m_healthMax;

public:
    // Constructor
    CharacterTpl(const char* name, int healthMax) : Character(name), m_healthMax(healthMax) {
        if constexpr (std::is_same<T, seneca::SuperHealth>::value || std::is_same<T, seneca::InfiniteHealth>::value) {
            m_health = T();  // For SuperHealth or InfiniteHealth, use default constructor
        } else {
            m_health = healthMax;  // For numeric types, initialize with healthMax
        }
    }
    // Override functions
    void takeDamage(int dmg) override {
        m_health -= dmg;
        if (static_cast<int>(m_health) <= 0) {
            std::cout << this->getName() << " has been defeated!" << std::endl;
            m_health = 0;  // Ensure health doesn't go below 0
        } else {
            std::cout << this->getName() << " took " << dmg << " damage, " << static_cast<int>(m_health) << " health remaining." << std::endl;
        }
    }

    int getHealth() const override {
        return static_cast<int>(m_health);
    }

    int getHealthMax() const override {
        return m_healthMax;
    }

    void setHealth(int health) override {
        m_health = health;
    }

    void setHealthMax(int health) override {
        m_healthMax = health;
        m_health = health;
    }
};

}

#endif
