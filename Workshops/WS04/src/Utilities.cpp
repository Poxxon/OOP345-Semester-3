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

#include "Utilities.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include <algorithm>

namespace seneca {

    char Utilities::m_delimiter{};

    // To set it field width to a new one
    void Utilities::setFieldWidth(size_t newWidth) {
        m_widthField = newWidth;
    }
    
    // Returns the field width
    size_t Utilities::getFieldWidth() const {
        return m_widthField;
    }

    // Extracts a token from the input string based om the current delimiter
    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

        // Condition to check if a delimiter is found at next_pos
        if (str[next_pos] == m_delimiter) {
            more = false;
            throw "Delimiter found in the next_pos";
        }

         // Token extraction
        std::string token{};
        size_t pos = str.find(m_delimiter, next_pos);

        if (pos != std::string::npos) { 
            token = str.substr(next_pos, pos - next_pos);
            next_pos = pos + 1;
            more = true;
        } else {
            token = str.substr(next_pos);
            next_pos = str.length();
            more = false;
        }

        while (!token.empty() && token.front() == ' ') {
            token.erase(0, 1);
        }
        while (!token.empty() && token.back() == ' ') {
            token.pop_back();
        }

        // Update m_widthField if the current value is less than the extracted token value 
        if (m_widthField < token.length()) {
            m_widthField = token.length();
        }

        return token;
    }

    void Utilities::setDelimiter(char newDelimiter) {
        m_delimiter = newDelimiter;
    }

    char Utilities::getDelimiter() {
        return m_delimiter;
    }
}
