//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NDD
//==============================================

#include "timeMonitor.h"

namespace seneca {

    void TimeMonitor::startEvent(const char* name) {
        m_eventName = name;  // Store the event name
        m_start = std::chrono::steady_clock::now();  // Record the start time
    }

    Event TimeMonitor::stopEvent() {
        auto end = std::chrono::steady_clock::now();  // Record the end time
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - m_start);  // Calculate the duration

        return Event(m_eventName.c_str(), duration);  // Create and return an Event object with the duration
    }
}
