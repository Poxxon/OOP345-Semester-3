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

#include "LineManager.h"
#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <algorithm>

namespace seneca {

// Constructor: Initializes the LineManager from a configuration file
LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
    try {
        std::ifstream input(file);
        if (!input) {
            throw std::string("Unable to open file: ") + file;
        }

        Utilities util;
        std::string record;

        // Parse each line in the file to set up the assembly line
        while (std::getline(input, record)) {
            size_t next_pos = 0;
            bool more = true;

            // Extract the current station name
            std::string current_name = util.extractToken(record, next_pos, more);

            // Find the corresponding station object
            auto current_station = std::find_if(stations.begin(), stations.end(),
                [&](Workstation* ws) { return ws->getItemName() == current_name; });

            if (current_station != stations.end()) {
                m_activeLine.push_back(*current_station);

                // If there is a next station, set the connection
                if (more) {
                    std::string next_name = util.extractToken(record, next_pos, more);
                    auto next_station = std::find_if(stations.begin(), stations.end(),
                        [&](Workstation* ws) { return ws->getItemName() == next_name; });

                    if (next_station != stations.end()) {
                        (*current_station)->setNextStation(*next_station);
                    }
                }
            }
        }

        // Find the first station in the sequence
        m_firstStation = *std::find_if(stations.begin(), stations.end(),
            [this](Workstation* ws) {
                return std::none_of(m_activeLine.begin(), m_activeLine.end(),
                    [ws](Workstation* nextWs) { return nextWs->getNextStation() == ws; });
            });

        // Count the total number of customer orders
        m_cntCustomerOrder = g_pending.size();
    } catch (const std::string& err) {
        throw err;
    }
}

// Reorders the stations in the correct processing sequence
void LineManager::reorderStations() {
    std::vector<Workstation*> orderedStations;
    Workstation* current = m_firstStation;

    // Follow the chain of stations to determine the correct order
    while (current != nullptr) {
        orderedStations.push_back(current);
        current = current->getNextStation();
    }

    m_activeLine = std::move(orderedStations);
}

// Runs one iteration of the assembly line
bool LineManager::run(std::ostream& os) {
    static size_t iteration_count = 1;
    os << "Line Manager Iteration: " << iteration_count++ << std::endl;

    // Move a pending order to the first station
    if (!g_pending.empty()) {
        *m_firstStation += std::move(g_pending.front());
        g_pending.pop_front();
    }

    // Process each station
    for (auto* station : m_activeLine) {
        station->fill(os);
    }

    // Attempt to move orders to the next station
    for (auto* station : m_activeLine) {
        station->attemptToMoveOrder();
    }

    // Check if all orders are completed or moved to incomplete
    return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;
}

// Displays the current status of the line
void LineManager::display(std::ostream& os) const {
    for (auto* station : m_activeLine) {
        station->display(os);
    }
}

} // namespace seneca
