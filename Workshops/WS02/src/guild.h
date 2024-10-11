#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H

#include "character.h"
#include <iostream>

namespace seneca {

class Guild {
private:
    std::string m_name;
    Character** m_members;
    size_t m_count;

    void cleanup() {
        for (size_t i = 0; i < m_count; ++i) {
            delete m_members[i];
        }
        delete[] m_members;
    }

public:
    Guild() : m_name(""), m_members(nullptr), m_count(0) {}

    Guild(const char* name) : m_name(name), m_members(nullptr), m_count(0) {}

    ~Guild() {
        cleanup();
    }

    Guild(const Guild& other) : m_name(other.m_name), m_members(nullptr), m_count(other.m_count) {
        if (m_count > 0) {
            m_members = new Character*[m_count];
            for (size_t i = 0; i < m_count; ++i) {
                m_members[i] = other.m_members[i]->clone();
                m_members[i]->setHealthMax(m_members[i]->getHealthMax() + 300);  // Add guild bonus
            }
        }
    }

    Guild& operator=(const Guild& other) {
        if (this != &other) {  
            cleanup(); 
            m_name = other.m_name;
            m_count = other.m_count;
            if (m_count > 0) {
                m_members = new Character*[m_count];
                for (size_t i = 0; i < m_count; ++i) {
                    m_members[i] = other.m_members[i]->clone();
                    m_members[i]->setHealthMax(m_members[i]->getHealthMax() + 300);  // Add guild bonus
                }
            }
        }
        return *this;
    }


    Guild(Guild&& other) noexcept : m_name(std::move(other.m_name)), m_members(other.m_members), m_count(other.m_count) {
        other.m_members = nullptr;  // Prevent double free by nullifying the original pointer
        other.m_count = 0;
    }   

    Guild& operator=(Guild&& other) noexcept {
        if (this != &other) {  // Self-assignment check
            cleanup();  // Clean up the existing resources
            m_name = std::move(other.m_name);
            m_members = other.m_members;
            m_count = other.m_count;
            other.m_members = nullptr;  // Prevent double free by nullifying the original pointer
            other.m_count = 0;
        }
        return *this;
    }

    void addMember(Character* c) {
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
        temp[m_count]->setHealthMax(temp[m_count]->getHealthMax() + 300);  // Guild bonus
        delete[] m_members;
        m_members = temp;
        ++m_count;
    }

    void removeMember(const std::string& name) {
        for (size_t i = 0; i < m_count; ++i) {
            if (m_members[i]->getName() == name) {
                m_members[i]->setHealthMax(m_members[i]->getHealthMax() - 300);  // Remove guild bonus
                delete m_members[i];
                for (size_t j = i; j < m_count - 1; ++j) {
                    m_members[j] = m_members[j + 1];
                }
                --m_count;
                break;
            }
        }
    }

    Character* operator[](size_t idx) const {
        if (idx < m_count) {
            return m_members[idx];
        }
        return nullptr;
    }

    // Guild.h
    void showMembers() const {
        if (m_count == 0) {
            std::cout << "No guild." << std::endl;
        } else {
            std::cout << "[Guild] " << m_name << std::endl;
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
