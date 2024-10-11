//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NDD
//==============================================

#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H

#include "event.h"

namespace seneca {
    class Logger {
    private:
        Event* m_events = nullptr;    // Dynamic array of events
        size_t m_size = 0;            // Number of stored events

        void resize();                // Helper function to resize the array if necessary

    public:
        Logger();                     // Default constructor
        ~Logger();                    // Destructor

        Logger(const Logger&) = delete;            // Disable copy constructor
        Logger& operator=(const Logger&) = delete; // Disable copy assignment

        Logger(Logger&& other);       // Move constructor
        Logger& operator=(Logger&& other);  // Move assignment operator

        void addEvent(const Event& event);  // Add event to the logger

        friend std::ostream& operator<<(std::ostream& os, const Logger& logger);  // Print all events
    };
}

#endif // SENECA_LOGGER_H
