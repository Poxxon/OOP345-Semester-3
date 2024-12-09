#include "Station.h"
#include "Utilities.h"
#include <iomanip>

namespace seneca {

    // Initialization 
    size_t Station::m_widthField = 0;
    int Station::id_generator = 0;

    // Constructor
    Station::Station(const std::string& record) {
        Utilities util;
        size_t next_pos = 0;
        bool more = true;

        m_id = ++id_generator; // Assign an id to the station

        // Parse the record using the utilities module
        m_name = util.extractToken(record, next_pos, more);
        m_serialNumber = std::stoul(util.extractToken(record, next_pos, more));
        m_quantity = std::stoul(util.extractToken(record, next_pos, more));
        m_description = util.extractToken(record, next_pos, more);

        // Update widthField
        if (m_widthField < util.getFieldWidth()) {
            m_widthField = util.getFieldWidth();
        }
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
            --m_quantity;
        }
    }

    // Display the station detail
    void Station::display(std::ostream& os, bool full) const {
        os << std::setw(3) << std::setfill('0') << m_id << " | "
          << std::setw(m_widthField) << std::left << m_name << " | "
          << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << " | ";

        if (full) {
            os << std::setw(4) << std::setfill(' ') << m_quantity << " | "
               << m_description;
        }
        os << std::endl;
    }
}