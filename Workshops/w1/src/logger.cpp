//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NDD
//==============================================

#include "logger.h"
#include <iostream>

namespace seneca {

    Logger::Logger() : m_events(nullptr), m_size(0) {}

    Logger::~Logger() {
        delete[] m_events;
    }

    // Move constructor
    Logger::Logger(Logger&& other) : m_events(other.m_events), m_size(other.m_size) {
        other.m_events = nullptr;
        other.m_size = 0;
    }

    // Move assignment operator
    Logger& Logger::operator=(Logger&& other) {
        if (this != &other) {
            delete[] m_events;

            m_events = other.m_events;
            m_size = other.m_size;

            other.m_events = nullptr;
            other.m_size = 0;
        }
        return *this;
    }

    void Logger::resize() {
        size_t newCapacity = m_size == 0 ? 2 : m_size * 2; // Dynamically increase capacity
        Event* newEvents = new Event[newCapacity];

        // Copy existing events
        for (size_t i = 0; i < m_size; ++i) {
            newEvents[i] = m_events[i];
        }

        // Free the old memory and update the pointer
        delete[] m_events;
        m_events = newEvents;
    }


    void Logger::addEvent(const Event& event) {
        if (m_size == 0 || m_events == nullptr) {
            m_events = new Event[1];
            m_events[m_size++] = event;
        } else {
            resize();
            m_events[m_size++] = event;
        }
    }

    std::ostream& operator<<(std::ostream& os, const Logger& logger) {
        for (size_t i = 0; i < logger.m_size; ++i) {
            os << logger.m_events[i] << std::endl;
        }
        return os;
    }
}
