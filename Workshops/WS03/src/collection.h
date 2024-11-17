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

#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "mediaItem.h"
namespace seneca {

// Represents a collection of MediaItem objects
class Collection {
    std::string m_name;                 // Name of the collection            
    std::vector<MediaItem*> m_items;    // Vector array for MediaItem pointers
    void (*m_observer)(const Collection&, const MediaItem&) = nullptr;  // Observer

public:
    // Constructor
    Collection(const std::string& name);

    // Destructor
    ~Collection();

    // Disable copy and move operations
    Collection(const Collection&) = delete;

    Collection& operator=(const Collection&) = delete;

    Collection(Collection&&) = delete;

    Collection& operator=(Collection&&) = delete;

    // Retrieve collection name
    const std::string& name() const;

    // Retrieve the size of the collection
    size_t size() const;

    // Set an observer callback
    void setObserver(void (*observer)(const Collection&, const MediaItem&));

    // Add a MediaItem to the collection
    Collection& operator+=(MediaItem* item);

    // Access a MediaItem by its index
    MediaItem* operator[](size_t idx) const;

    // Access a MediaItem by its title
    MediaItem* operator[](const std::string& title) const;

    // Remove quotes from MediaItem titles and summaries
    void removeQuotes();

    // Sort the collection by a specified field
    void sort(const std::string& field);

    // friend func
    friend std::ostream& operator<<(std::ostream& out, const Collection& collection);
};
}  

#endif // SENECA_COLLECTION_H
