#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H

#include "characterTpl.h"
#include "weapons.h"
#include "abilities.h"
#include <iostream>

namespace seneca {

template<typename T, typename Ability_t, typename Weapon_t>
class Barbarian : public CharacterTpl<T> {
private:
    int m_baseAttack;
    int m_baseDefense;
    Ability_t m_ability;
    Weapon_t m_weapons[2];  // Two weapons

public:
    Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon)
        : CharacterTpl<T>(name, healthMax), m_baseAttack(baseAttack), m_baseDefense(baseDefense) {
        m_weapons[0] = primaryWeapon;
        m_weapons[1] = secondaryWeapon;
    }

    // Implement attack
    int getAttackAmnt() const override {
        return m_baseAttack + static_cast<int>(m_weapons[0]) / 2 + static_cast<int>(m_weapons[1]) / 2;
    }

    int getDefenseAmnt() const override {
        return m_baseDefense;
    }

    Character* clone() const override {
        return new Barbarian(*this);
    }

    void attack(Character* enemy) override {
        std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
        m_ability.useAbility(this);
        int damage = getAttackAmnt();
        m_ability.transformDamageDealt(damage);
        std::cout << "Barbarian deals " << damage << " melee damage!" << std::endl;
        enemy->takeDamage(damage);
    }

    void takeDamage(int dmg) override {
        std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
        std::cout << "Barbarian has a defense of " << m_baseDefense << ". Reducing damage received." << std::endl;
        dmg -= m_baseDefense;
        if (dmg < 0) dmg = 0;
        m_ability.transformDamageReceived(dmg);
        CharacterTpl<T>::takeDamage(dmg);
    }
};

}

#endif
