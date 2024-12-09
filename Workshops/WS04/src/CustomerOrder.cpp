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

#include <iostream>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

namespace seneca {

size_t CustomerOrder::m_widthField = 0; // Initialize the static field for alignment

// Parses a single input string to initialize a customer order
CustomerOrder::CustomerOrder(const std::string &input) {
    Utilities ut;
    size_t next_pos = 0;
    bool more = true;

    // Extract the customer's name and product
    m_name = ut.extractToken(input, next_pos, more);
    m_product = ut.extractToken(input, next_pos, more);

    // Count the number of items in the order
    size_t count_pos = next_pos;
    bool more_items = true;
    while (more_items) {
        ut.extractToken(input, count_pos, more_items);
        m_cntItem++;
    }

    // Allocate memory for items and populate it by extracting tokens
    m_lstItem = new Item*[m_cntItem];
    for (size_t i = 0; i < m_cntItem && more; i++) {
        std::string item_name = ut.extractToken(input, next_pos, more);
        m_lstItem[i] = new Item(item_name);
    }

    // Update the field width for proper alignment in output
    if (m_widthField < ut.getFieldWidth()) {
        m_widthField = ut.getFieldWidth();
    }
}

// Making sure to throw an exception if an attempt to copying is made
CustomerOrder::CustomerOrder(const CustomerOrder &) {
    throw "Copies cannot be made";
}

// Transfers ownership of resources from the source object
CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
    *this = std::move(src);
}

// Safely transfers ownership from the source object
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
    if (this == &src) {
        return *this;
    }

    // Free any existing resources
    for (size_t i = 0; i < m_cntItem; i++) {
        delete m_lstItem[i];
    }
    delete[] m_lstItem;

    // Transfer ownership of resources
    m_name = std::move(src.m_name);
    m_product = std::move(src.m_product);
    m_cntItem = src.m_cntItem;
    m_lstItem = src.m_lstItem;

    // Reset the source object
    src.m_cntItem = 0;
    src.m_lstItem = nullptr;

    return *this;
}

// Releases all dynamically allocated resources
CustomerOrder::~CustomerOrder() {
    for (size_t i = 0; i < m_cntItem; i++) {
        delete m_lstItem[i];
    }
    delete[] m_lstItem;
    m_lstItem = nullptr;
}

// Checks if the entire order is filled
bool CustomerOrder::isOrderFilled() const {
    for (size_t i = 0; i < m_cntItem; i++) {
        if (!m_lstItem[i]->m_isFilled) {
            return false;
        }
    }
    return true;
}

// Checks if a specific item in the order is filled
bool CustomerOrder::isItemFilled(const std::string &itemName) const {
    for (size_t i = 0; i < m_cntItem; i++) {
        if (m_lstItem[i]->m_itemName == itemName) {
            if (!m_lstItem[i]->m_isFilled) {
                return false;
            }
        }
    }
    return true;
}

// Attempts to fill an item at the given station
void CustomerOrder::fillItem(Station &station, std::ostream &os) {
    for (size_t i = 0; i < m_cntItem; i++) { // Loop through all items
        if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled) {
            if (station.getQuantity() > 0) { // Fill the item if the station has stock
                station.updateQuantity();
                m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                m_lstItem[i]->m_isFilled = true;
                os << "    Filled " << m_name << ", " << m_product << " ["
                   << m_lstItem[i]->m_itemName << "]" << std::endl;
                return; // Exit after filling one item
            } else { // Station is out of stock
                os << "    Unable to fill " << m_name << ", " << m_product
                   << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
            }
        }
    }
}

// Displays the order's details in a formatted manner
void CustomerOrder::display(std::ostream &os) const {
    os << m_name << " - " << m_product << std::endl;
    for (size_t i = 0; i < m_cntItem; i++) {
        os << "[" << std::setw(6) << std::setfill('0') << std::right
           << m_lstItem[i]->m_serialNumber << "] "
           << std::setw(m_widthField) << std::setfill(' ') << std::left
           << m_lstItem[i]->m_itemName << " - "
           << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
    }
}
}
