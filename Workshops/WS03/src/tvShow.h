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

// Forward declaration of TvShow
class TvShow;

struct TvEpisode {
    const TvShow* m_show{};            // Pointer to the parent TV show
    unsigned short m_numberOverall{};  // Overall episode number across seasons
    unsigned short m_season{};         // Season number
    unsigned short m_numberInSeason{}; // Episode number within the season
    std::string m_airDate{};           // Air date of the episode
    unsigned int m_length{};           // Length of the episode in seconds
    std::string m_title{};             // Title of the episode
    std::string m_summary{};           // Summary of the episode

    // Constructs a TvEpisode object with specified details.
    TvEpisode(const TvShow* show, unsigned short numberOverall, unsigned short season,
              unsigned short numberInSeason, const std::string& airDate,
              unsigned int length, const std::string& title,
              const std::string& summary)
        : m_show(show), m_numberOverall(numberOverall), m_season(season),
          m_numberInSeason(numberInSeason), m_airDate(airDate), m_length(length),
          m_title(title), m_summary(summary) {}
};

class TvShow : public MediaItem {
    std::string m_id;                     // Unique identifier for the TV show
    std::vector<TvEpisode> m_episodes;    // List of episodes in the TV show

    // Private constructor to enforce controlled creation of TvShow objects.
    TvShow(const std::string& id, const std::string& title, const std::string& summary, unsigned short year)
        : MediaItem(title, summary, year), m_id(id) {}

public:
    // Displays the TV show and its episodes to the provided output stream.
    void display(std::ostream& out) const override;

    // Creates a TvShow object from a CSV-formatted string.
    static TvShow* createItem(const std::string& strShow);

    // Adds an episode to the TV show collection from a CSV-formatted string.
    template <typename Collection_t>
    static void addEpisode(Collection_t& col, const std::string& strEpisode) {
        if (strEpisode.empty() || strEpisode[0] == '#') {
            throw "Not a valid episode."; // Skip empty or comment lines
        }

        std::istringstream stream(strEpisode);
        std::string id, airDate, lengthStr, title, summary, seasonStr;
        unsigned short numberOverall, season = 1, numberInSeason;

        // Lambda to parse time strings in hh:mm:ss format
        auto parseTime = [](const std::string& timeStr) -> unsigned int {
            unsigned int hours = 0, minutes = 0, seconds = 0;
            char delimiter; // For ':'
            std::istringstream timeStream(timeStr);
            timeStream >> hours >> delimiter >> minutes >> delimiter >> seconds;
            return hours * 3600 + minutes * 60 + seconds; // Convert to seconds
        };

        // Parse the CSV fields
        std::getline(stream, id, ',');               // ID
        stream >> numberOverall;                     // Overall episode number
        stream.ignore();                             // Ignore comma
        std::getline(stream, seasonStr, ',');        // Season number
        stream >> numberInSeason;                    // Episode number in season
        stream.ignore();                             // Ignore comma
        std::getline(stream, airDate, ',');          // Air date
        std::getline(stream, lengthStr, ',');        // Episode length as a string
        std::getline(stream, title, ',');            // Title
        std::getline(stream, summary);               // Summary

        // Trim whitespace from fields
        trim(id);
        trim(seasonStr);
        trim(airDate);
        trim(lengthStr);
        trim(title);
        trim(summary);

        // Handle missing season number
        if (seasonStr.empty()) {
            season = 1; // Default to season 1
        } else {
            try {
                season = std::stoi(seasonStr); // Convert to integer
            } catch (...) {
                season = 1;
            }
        }

        // Convert episode length to seconds
        unsigned int lengthInSeconds = parseTime(lengthStr);

        // Find the matching TV show by ID in the collection
        TvShow* matchingShow = nullptr;
        for (size_t i = 0; i < col.size(); ++i) {
            MediaItem* item = col[i];
            TvShow* show = dynamic_cast<TvShow*>(item);
            if (show && show->m_id == id) {
                matchingShow = show;
                break;
            }
        }
        if (!matchingShow) {
            throw "Show not found for episode."; // Error if no matching show
        }

        // Create and add the episode to the TV show
        TvEpisode episode = {matchingShow, numberOverall, season, numberInSeason, airDate, lengthInSeconds, title, summary};
        matchingShow->m_episodes.push_back(episode);
    }

    // Calculates the average length of episodes in the TV show.
    double getEpisodeAverageLength() const;


    // Retrieves a list of titles of episodes longer than 60 minutes.
    std::list<std::string> getLongEpisodes() const;
};
}

#endif // SENECA_TVSHOW_H
