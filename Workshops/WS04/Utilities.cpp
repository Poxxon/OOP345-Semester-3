#include "Utilities.h"
#include <stdexcept>
#include <string>
#include <iostream>
#include <algorithm>

namespace seneca {

    char Utilities::m_delimiter = ','; // For default delimiter

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
        if (next_pos >= str.length()) {
            more = false;
            return "";
        }

        // Throw runtime error if delimiter is at the starting position 
        size_t delimiter_pos = str.find(m_delimiter, next_pos);
        if (delimiter_pos == next_pos) {
            throw std::runtime_error("Delimiter found no token at next pos");
        }

        // Token extraction
        std::string token;
        if (delimiter_pos == std::string::npos) {
            token = str.substr(next_pos);
            next_pos = str.length();
            more = false;
        } else {
            // Update next_pos for the next token after extracting token
            token = str.substr(next_pos, delimiter_pos - next_pos);
            next_pos = delimiter_pos + 1;
            more = true;
        }

        // For trimming spaces from the token
        token.erase(0, token.find_first_not_of(' '));
        token.erase(token.find_last_not_of(' ') + 1);

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
