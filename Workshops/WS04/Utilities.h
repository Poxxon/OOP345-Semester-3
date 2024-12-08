#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include <string>

namespace seneca {

class Utilities {
    size_t m_widthField = 1; // For the length of token extracted
    static char m_delimiter; // For shared delimiter in all objects

public:
    void setFieldWidth(size_t newWidth);
    size_t getFieldWidth() const;

    std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

    static void setDelimiter(char newDelimiter);
    static char getDelimiter();
};

}

#endif //SENECA_UTILITIES_H