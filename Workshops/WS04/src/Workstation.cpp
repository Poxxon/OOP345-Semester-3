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

#include "Workstation.h"
#include <iostream>

namespace seneca {

// Global queues
std::deque<CustomerOrder> g_pending;
std::deque<CustomerOrder> g_completed;
std::deque<CustomerOrder> g_incomplete;

// Constructor: Initializes a workstation using the provided data string
Workstation::Workstation(const std::string& data) : Station(data) {}

// Fills the front order in the queue, if any
void Workstation::fill(std::ostream& os) {
    if (!m_orders.empty()) {
        m_orders.front().fillItem(*this, os);
    }
}

// Sets the next station in the assembly line
void Workstation::setNextStation(Workstation* station) {
    m_pNextStation = station;
}

// Gets the pointer to the next station
Workstation* Workstation::getNextStation() const {
    return m_pNextStation;
}

// Adds a new order to the workstation queue
Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
    m_orders.push_back(std::move(newOrder));
    return *this;
}

// Attempts to move the front order to the next station
bool Workstation::attemptToMoveOrder() {
    if (m_orders.empty()) {
        return false;
    }

    CustomerOrder& currentOrder = m_orders.front();

    // Move the order to the next station or the appropriate global queue
    if (currentOrder.isItemFilled(getItemName()) || getQuantity() <= 0) {
        if (m_pNextStation) {
            *m_pNextStation += std::move(currentOrder);
        } else {
            if (currentOrder.isOrderFilled()) {
                g_completed.push_back(std::move(currentOrder));
            } else {
                g_incomplete.push_back(std::move(currentOrder));
            }
        }

        // Remove the order from the current workstation
        m_orders.pop_front();
        return true;
    }

    return false;
}

// Displays the current workstation and its next station
void Workstation::display(std::ostream& os) const {
    os << getItemName() << " --> "
       << (m_pNextStation ? m_pNextStation->getItemName() : "End of Line")
       << std::endl;
}

} // namespace seneca
