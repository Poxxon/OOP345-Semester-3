/*===============================================================
Name:           Pouya Rad
Student Number: 164382228
Email:          prad@myseneca.ca
Section:        NDD

I declare that this submission is the result of my own work and I
only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not
been shared with any other student or 3rd party content provider.
=================================================================*/

#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H
namespace seneca {

struct Settings {
    short m_maxSummaryWidth = 80; // Maximum width for displaying summaries
    bool m_tableView = false;     // Whether to display items in a table format
};

// Declaration of a global settings object
extern Settings g_settings;
}

#endif // SENECA_SETTINGS_H
