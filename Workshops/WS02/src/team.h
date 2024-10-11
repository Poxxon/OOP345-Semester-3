#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H

#include "character.h"
#include <iostream>
#include <cstring>

namespace seneca {

class Team {
private:
    std::string m_name;
    Character** m_members;
    size_t m_count;

    // Helper to clean up memory
    void cleanup() {
        for (size_t i = 0; i < m_count; ++i) {
            delete m_members[i];
        }
        delete[] m_members;
    }

public:
    // Default constructor
    Team() : m_name(""), m_members(nullptr), m_count(0) {}

    // Constructor with team name
    Team(const char* name) : m_name(name), m_members(nullptr), m_count(0) {}

    // Rule of 5: Destructor
    ~Team() {
        cleanup();
    }

    // Rule of 5: Copy constructor
    Team(const Team& other) : m_name(other.m_name), m_members(nullptr), m_count(other.m_count) {
        if (m_count > 0) {
            m_members = new Character*[m_count];
            for (size_t i = 0; i < m_count; ++i) {
                m_members[i] = other.m_members[i]->clone();
            }
        }
    }

    // Rule of 5: Copy assignment operator
    Team& operator=(const Team& other) {
        if (this != &other) { 
            cleanup();  
            m_name = other.m_name;
            m_count = other.m_count;
            if (m_count > 0) {
                m_members = new Character*[m_count];
                for (size_t i = 0; i < m_count; ++i) {
                    m_members[i] = other.m_members[i]->clone();
                }
            }
        }
        return *this;
    }

    // Rule of 5: Move constructor
    Team(Team&& other) noexcept : m_name(std::move(other.m_name)), m_members(other.m_members), m_count(other.m_count) {
        other.m_members = nullptr; 
        other.m_count = 0;
    }

    // Rule of 5: Move assignment operator
    Team& operator=(Team&& other) noexcept {
        if (this != &other) {  
            cleanup();  
            m_name = std::move(other.m_name);
            m_members = other.m_members;
            m_count = other.m_count;
            other.m_members = nullptr; 
            other.m_count = 0;
        }
        return *this;
    }

    // Add member function
    void addMember(const Character* c) {
        for (size_t i = 0; i < m_count; ++i) {
            if (m_members[i]->getName() == c->getName()) {
                return;
            }
        }
        Character** temp = new Character*[m_count + 1];
        for (size_t i = 0; i < m_count; ++i) {
            temp[i] = m_members[i];
        }
        temp[m_count] = c->clone();
        delete[] m_members;
        m_members = temp;
        ++m_count;
    }

    // Remove member by name
    void removeMember(const std::string& name) {
        for (size_t i = 0; i < m_count; ++i) {
            if (m_members[i]->getName() == name) {
                delete m_members[i];
                for (size_t j = i; j < m_count - 1; ++j) {
                    m_members[j] = m_members[j + 1];
                }
                --m_count;
                break;
            }
        }
    }

    // Overloaded [] operator to access members
    Character* operator[](size_t idx) const {
        if (idx < m_count) {
            return m_members[idx];
        }
        return nullptr;
    }

    // Show members
    // Team.h
    void showMembers() const {
        if (m_count == 0) {
            std::cout << "No team." << std::endl;
        } else {
            std::cout << "[Team] " << m_name << std::endl;
            for (size_t i = 0; i < m_count; ++i) {
                Character* member = m_members[i];
                std::cout << "    " << i + 1 << ": " << member->getName()
                          << "            Health: " << member->getHealth() * 100 / member->getHealthMax() << "% ("
                          << member->getHealth() << "/" << member->getHealthMax() << ")  "
                          << "Attack: " << member->getAttackAmnt() << "  "
                          << "Defense: " << member->getDefenseAmnt() << std::endl;
            }
        }
    }

};

}

#endif
