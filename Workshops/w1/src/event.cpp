//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NDD
//==============================================

#include "event.h"
#include "settings.h"

namespace seneca {

    std::ostream& operator<<(std::ostream& os, const Event& event) {
        static int counter = 1;  // Counter to track the number of times the function is called
        os.width(2);
        os << counter++ << ": ";
        os.width(40);
        os << std::right << event.m_eventName << " -> ";

        // Adjust the width based on the time unit
    if (g_settings.m_time_units == "seconds") {
        os.width(2);  // For seconds, width is 2
        os << std::right << std::chrono::duration_cast<std::chrono::seconds>(event.m_duration).count();
    } else if (g_settings.m_time_units == "milliseconds") {
        os.width(5);  // For milliseconds, width is 5
        os << std::right << std::chrono::duration_cast<std::chrono::milliseconds>(event.m_duration).count();
    } else if (g_settings.m_time_units == "microseconds") {
        os.width(8);  // For microseconds, width is 8
        os << std::right << std::chrono::duration_cast<std::chrono::microseconds>(event.m_duration).count();
    } else {
        os.width(11);  // For nanoseconds, width is 11
        os << std::right << event.m_duration.count();
    }

        os << " " << g_settings.m_time_units;
        return os;
    }
}
