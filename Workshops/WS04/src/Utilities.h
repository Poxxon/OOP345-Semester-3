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

#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include <string>

namespace seneca {

class Utilities {
    size_t m_widthField = 1; // For the length of token extracted
    static char m_delimiter; // For shared delimiter in all objects

public:
    void setFieldWidth(size_t newWidth); // Sets the field width to a specific value
    size_t getFieldWidth() const;        // Returns the current field width

    // Extracts the token for the given string using the delimiter
    std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

    static void setDelimiter(char newDelimiter);
    static char getDelimiter();
};

}

#endif //SENECA_UTILITIES_H