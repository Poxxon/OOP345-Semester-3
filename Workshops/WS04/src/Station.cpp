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

#include "Station.h"
#include "Utilities.h"
#include <iomanip>

namespace seneca {

    // Initialization 
    size_t Station::m_widthField = 0;
    int Station::id_generator = 0;

    // Constructor
    Station::Station(const std::string& record) {
        Utilities util{};
        size_t next_pos{};
        bool more{};

        m_id = ++id_generator; // Assign an id to the station

        // Parse the record using the utilities module
        m_name = util.extractToken(record, next_pos, more);
        // To align the output 
        if (m_widthField < util.getFieldWidth()) {
            m_widthField = util.getFieldWidth();
        }
        // Parse serial number and cast to size_t and reassign
        m_serialNumber = static_cast<size_t>(std::stoi(util.extractToken(record, next_pos, more)));
        // Parse quantity and do the same as above
        m_quantity = static_cast<size_t>(std::stoi(util.extractToken(record, next_pos, more)));
        // Parse desc
        m_description = util.extractToken(record, next_pos, more);
    }

    // Return the name of the item
    const std::string& Station::getItemName() const {
        return m_name;
    }

    // Return the next serial number and increment it
    size_t Station::getNextSerialNumber() {
        return m_serialNumber++;
    }

    // Return the quantity of items in stock
    size_t Station::getQuantity() const {
        return m_quantity;
    }

    // Decrease the quantity by 1
    void Station::updateQuantity() {
        if (m_quantity > 0) {
            m_quantity--;
        }
    }

    // Display the station detail
    void Station::display(std::ostream &os, bool full) const {
        os << std::setw(3) << std::setfill('0') << std::right << m_id << " | "
           << std::setw(static_cast<int>(m_widthField)) << std::setfill(' ') << std::left << m_name << " | "
           << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << " | ";
        if (full) {
            os << std::setw(4) << std::setfill(' ') << std::right << m_quantity << " | "
               << m_description;
        }
        os << std::endl;
    }
}