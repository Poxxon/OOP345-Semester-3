//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NDD
//==============================================

#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H

#include "event.h"
#include <chrono>
#include <string>

namespace seneca {
    class TimeMonitor {
    private:
        std::string m_eventName;                       // Name of the current event
        std::chrono::steady_clock::time_point m_start; // Start time of the event
    public:
        void startEvent(const char* name);             // Start an event
        Event stopEvent();                             // Stop the event and return an Event instance
    };
}

#endif // SENECA_TIMEMONITOR_H
