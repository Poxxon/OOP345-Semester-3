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

#ifndef SENECA_STATION_H
#define SENECA_STATION_H

#include <string>
#include <iostream>

namespace seneca {

    class Station {

        int m_id{};                     // ID for each station
        std::string m_name{};           // Name of item
        std::string m_description{};    // Desc of the station
        size_t m_serialNumber{};        // Serial number of the next item
        size_t m_quantity{};            // Numbers of items in stock
        static size_t m_widthField;     // Max width of the item name
        static int id_generator;        // Counter for each time generating an ID

    public:
        // Constructor
        Station(const std::string& record);

        // Return the name of the handled item
        const std::string& getItemName() const;

        // Return the next serial number 
        size_t  getNextSerialNumber();

        // Return the quantity of stock items
        size_t getQuantity() const;

        // Updated the item quantity
        void updateQuantity();

        // Display station details
        void display(std::ostream& os, bool full) const;
    };
}

#endif