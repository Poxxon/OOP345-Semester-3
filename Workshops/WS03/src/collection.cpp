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

#include "collection.h"
#include <stdexcept>
#include <iomanip>
namespace seneca {

// Constructor to initialize a collection with a name
Collection::Collection(const std::string& name) : m_name(name) {}

// Destructor to delete all MediaItem objects 
Collection::~Collection() {
    for (auto item : m_items) {
        delete item;  // Free memory for each MediaItem
    }
}

// Get the name of the collection
const std::string& Collection::name() const {
    return m_name;
}

// Get the amount of MediaItem objects in the collection
size_t Collection::size() const {
    return m_items.size();
}

// Observer callback
void Collection::setObserver(void (*observer)(const Collection&, const MediaItem&)) {
    m_observer = observer;
}

// Adds a MediaItem to the collection, avoids dups 
Collection& Collection::operator+=(MediaItem* item) {
    // Check for duplicates by comparing titles
    auto it = std::find_if(m_items.begin(), m_items.end(),
        [item](const MediaItem* existingItem) {
            return existingItem->getTitle() == item->getTitle();
        });
    if (it != m_items.end()) {
        delete item;  // Delete the dup item 
    } else {
        m_items.push_back(item);  // Add the new item
        if (m_observer) {
            m_observer(*this, *item);  // Observer callback called if set
        }
    }
    return *this;
}

// Access a MediaItem through index
MediaItem* Collection::operator[](size_t idx) const {
    if (idx >= m_items.size()) {
        throw std::out_of_range("Bad index [" + std::to_string(idx) +                                  
                                "]. Collection has [" + std::to_string(m_items.size()) + "] items."); // throw out of range exception
    }
    return m_items[idx];
}

// Access a MediaItem by its title
MediaItem* Collection::operator[](const std::string& title) const {
    auto it = std::find_if(m_items.begin(), m_items.end(),
        [title](const MediaItem* item) {
            return item->getTitle() == title;
        });
    return (it != m_items.end()) ? *it : nullptr;
}

// Remove surrounding quotes from MediaItem titles and summaries
std::string trimQuotes(const std::string& str) {
    if (str.empty()) return str;

    if (str.front() == '"' && str.back() == '"') {
        return str.substr(1, str.size() - 2); // Remove both quotes
    } else if (str.front() == '"') {
        return str.substr(1); // Remove leading quote
    } else if (str.back() == '"') {
        return str.substr(0, str.size() - 1); // Remove trailing quote
    }
    return str;
}

void Collection::removeQuotes() {
    for (auto& item : m_items) {
        if (item) { // Ensure the item is not null
            item->setTitle(trimQuotes(item->getTitle()));   // Update title
            item->setSummary(trimQuotes(item->getSummary())); // Update summary
        }
    }
}

// Sorts the MediaItem in the collection based on a specific field
void Collection::sort(const std::string& field) {
    if (field == "title") {
        std::sort(m_items.begin(), m_items.end(), 
            [](const MediaItem* a, const MediaItem* b) { 
                return a->getTitle() < b->getTitle(); // Compare by their title
            });
    } else if (field == "year") {
        std::sort(m_items.begin(), m_items.end(),
            [](const MediaItem* a, const MediaItem* b) {
                return a->getYear() < b->getYear(); // Compare by their years
            });
    }
}

// Display details
std::ostream& operator<<(std::ostream& out, const Collection& collection) {
    for (const auto& item : collection.m_items) {
        out << *item;
    }
    return out;
}

} // namespace end
