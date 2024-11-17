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

#ifndef SENECA_TVSHOW_H
#define SENECA_TVSHOW_H

#include "mediaItem.h"
#include "settings.h"
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>

namespace seneca {

// Represents a TV episode
struct TvEpisode {
    const TvShow* m_show{};            // Pointer to parent TV show
    unsigned short m_numberOverall{};  // Overall episode number
    unsigned short m_season{};         // Season number
    unsigned short m_numberInSeason{}; // Episode number in the season
    std::string m_airDate{};           // Air date
    unsigned int m_length{};           // Length in seconds
    std::string m_title{};             // Title of the episode
    std::string m_summary{};           // Summary of the episode

    // Constructor for TvEpisode
    TvEpisode(const TvShow* show, unsigned short numberOverall, unsigned short season,
              unsigned short numberInSeason, const std::string& airDate,
              unsigned int length, const std::string& title, const std::string& summary)
        : m_show(show), m_numberOverall(numberOverall), m_season(season),
          m_numberInSeason(numberInSeason), m_airDate(airDate), m_length(length),
          m_title(title), m_summary(summary) {}
};

// Represents a TV show
class TvShow : public MediaItem {
    std::string m_id;                     // Unique identifier for the show
    std::vector<TvEpisode> m_episodes;    // List of episodes

    // Private constructor to enforce controlled creation
    TvShow(const std::string& id, const std::string& title, const std::string& summary, unsigned short year)
        : MediaItem(title, summary, year), m_id(id) {}

public:
    // Display the TV show and episodes
    void display(std::ostream& out) const override;

    // Create a TV show from a CSV string
    static TvShow* createItem(const std::string& strShow);

    // Add an episode to a collection of TV shows
    template <typename Collection_t>
    static void addEpisode(Collection_t& col, const std::string& strEpisode);

    // Get the average length of episodes
    double getEpisodeAverageLength() const;

    // Get titles of episodes longer than 60 minutes
    std::list<std::string> getLongEpisodes() const;
};
}

#endif // SENECA_TVSHOW_H
