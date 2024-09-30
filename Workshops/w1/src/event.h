//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NDD
//==============================================

#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

#include <string>
#include <chrono>
#include <iostream>

namespace seneca {

    class Event {
    private:
        std::string m_eventName;
        std::chrono::nanoseconds m_duration;

    public:
        Event() : m_eventName(""), m_duration(0) {}  // Default constructor

        Event(const char* name, const std::chrono::nanoseconds& duration)
            : m_eventName(name), m_duration(duration) {}

        friend std::ostream& operator<<(std::ostream& os, const Event& event);
    };
}

#endif // SENECA_EVENT_H
