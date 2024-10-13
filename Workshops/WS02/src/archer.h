#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H

#include "characterTpl.h"
#include "health.h"
#include <iostream>

namespace seneca {

template <typename Weapon_t> class Archer : public CharacterTpL<SuperHealth> {
  int m_baseAttack;
  int m_baseDefense;

  Weapon_t m_weapon;

public:
  // Constructor to initialize Archer with name, health, attack, defense, and weapon
  Archer(const char *name, int healthMax, int baseAttack, int baseDefense,
         Weapon_t weapon)
      : CharacterTpL<SuperHealth>(name, healthMax), m_baseAttack(baseAttack),
        m_baseDefense(baseDefense), m_weapon(weapon) {}

  // Copy constructor
  Archer(const Archer &other) : CharacterTpL<SuperHealth>(other) {
    m_baseAttack = other.m_baseAttack;
    m_baseDefense = other.m_baseDefense;
    m_weapon = other.m_weapon;
  }

  // Returns adjusted attack amount
  int getAttackAmnt() const override { return m_baseAttack * 1.3; }

  // Returns adjusted defense amount
  int getDefenseAmnt() const override { return m_baseDefense * 1.2; }

  // Clone method for duplicating an Archer
  Character *clone() const override { return new Archer(*this); }

  // Archer attacking an enemy character
  void attack(Character *enemy) override {
    std::cout << CharacterTpL<SuperHealth>::getName() << " is attacking "
              << enemy->getName() << ".\n";
    int dmg = getAttackAmnt();
    std::cout << "Archer deals " << dmg << " ranged damage!\n";
    enemy->takeDamage(dmg);
  }
  
  // Take damage and reduce it by defense value
  void takeDamage(int dmg) override {
    std::cout << CharacterTpL<SuperHealth>::getName() << " is attacked for "
              << dmg << "damage.\n";
    std::cout << "    Archer has a defense of " << getDefenseAmnt()
              << ". Reducing damage received.\n";

    dmg -= getDefenseAmnt();
    if (dmg < 0) {
      dmg = 0;
    }

    CharacterTpL<SuperHealth>::takeDamage(dmg);
  }
};

} // namespace seneca

#endif