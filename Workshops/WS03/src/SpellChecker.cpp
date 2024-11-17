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

#include "spellChecker.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>  
namespace seneca {

// Constructor that loads "bad" and "good" word pairs from a file
SpellChecker::SpellChecker(const char* filename) {
    std::ifstream file(filename); // Open the file
    if (!file) {
        throw "bad file name"; // Throw an error if the file cannot be opened
    }

    std::string line;  // Buffer for each line
    size_t index = 0;  // Index for word pairs

    // Read the file line by line until the limit (6 pairs) is reached
    while (std::getline(file, line) && index < 6) {
        std::istringstream stream(line); // Parse the line
        stream >> m_badWords[index] >> m_goodWords[index]; // Extract bad and good words
        ++index;
    }

    // Ensure at least 6 word pairs are loaded
    if (index < 6) {
        throw "file does not contain enough word pairs.";
    }
}

// Functor tha replaces bad words in the input text with their corresponding good words
void SpellChecker::operator()(std::string& text) {
    for (size_t i = 0; i < 6; ++i) { // Loop through all word pairs
        size_t position = text.find(m_badWords[i]); // Find the first occurrence of a bad word
        while (position != std::string::npos) { // Continue while bad words are found
            text.replace(position, m_badWords[i].length(), m_goodWords[i]); // Replace the bad word
            ++m_replacementCounts[i]; // Increment the replacement count for this pair
            position = text.find(m_badWords[i], position + m_goodWords[i].length()); // Search for the next occurrence
        }
    }
}

// Displays replacement statistics
void SpellChecker::showStatistics(std::ostream& out) const {
    out << "Spellchecker Statistics\n";
    for (size_t i = 0; i < 6; ++i) { // Loop through all word pairs
        out << std::left << std::setw(15) << m_badWords[i] << ": "  // Display bad word
            << m_replacementCounts[i] << " replacements" << std::endl; // Display replacement count
    }
}

} // namespace end
