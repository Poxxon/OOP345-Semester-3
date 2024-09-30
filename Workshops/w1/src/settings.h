//==============================================
// Name:           Pouya Rad
// Student Number: 164382228
// Email:          prad@myseneca.ca
// Section:        NDD
//==============================================

#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H

#include <string>

namespace seneca {
    struct Settings {
        bool m_show_all = false;      // Show all definitions if true, otherwise only the first one
        bool m_verbose = false;       // Print part-of-speech if true
        std::string m_time_units = "nanoseconds"; // Units for time measurements: seconds, milliseconds, etc.
    };

    extern Settings g_settings;       // Global settings variable
}

#endif // SENECA_SETTINGS_H
