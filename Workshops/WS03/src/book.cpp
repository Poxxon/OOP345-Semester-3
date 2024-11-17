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

#include "book.h"
#include <sstream>
namespace seneca {

// Display the book information in the following formatted way
void Book::display(std::ostream& out) const {
    if (g_settings.m_tableView) { // If table view is enabled
        out << "B | ";
        out << std::left << std::setfill('.');
        out << std::setw(50) << this->getTitle() << " | "; // for title
        out << std::right << std::setfill(' ');
        out << std::setw(2) << this->m_country << " | "; // for country
        out << std::setw(4) << this->getYear() << " | "; // for year
        out << std::left;

        // Display the summary with a maximum width
        if (g_settings.m_maxSummaryWidth > -1) {
            if (static_cast<short>(this->getSummary().size()) <= g_settings.m_maxSummaryWidth)
                out << this->getSummary();
            else
                out << this->getSummary().substr(0, g_settings.m_maxSummaryWidth - 3) << "...";
        } else {
            out << this->getSummary();
        }
        out << std::endl;
        
    } else { // otherwise if detailed view is enabled
        size_t pos = 0;
        out << this->getTitle() << " [" << this->getYear() << "] [";
        out << m_author << "] [" << m_country << "] [" << m_price << "]\n";
        out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << '\n';
       
        // Display the summary in chunks of max width
        while (pos < this->getSummary().size()) {
            out << "    " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth) << '\n';
            pos += g_settings.m_maxSummaryWidth;
        }
        out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << std::setfill(' ') << '\n';
    }
}

// Create a book object from CVS-formatted string
Book* Book::createItem(const std::string& strBook) {
    if (strBook.empty() || strBook[0] == '#') {
        throw "Not a valid book."; // Throw an exception for invalid book data
    }

    std::istringstream stream(strBook); // Parse the input string
    std::string author, title, country, priceStr, yearStr, summary;

    // Extract fields from separated by commas
    std::getline(stream, author, ',');
    std::getline(stream, title, ',');
    std::getline(stream, country, ',');
    std::getline(stream, priceStr, ',');
    std::getline(stream, yearStr, ',');
    std::getline(stream, summary);

    // Trim the whitespaces from the extracted fields from above
    trim(author);
    trim(title);
    trim(country);
    trim(summary);

    // Convert year and price to their appropriate types
    unsigned short year = std::stoi(yearStr);
    double price = std::stod(priceStr);

    // Return a new book object
    return new Book(title, summary, year, author, country, price);
}

}  // namespace end
