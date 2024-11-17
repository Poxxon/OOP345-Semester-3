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

class TvShow;

// structure for episode
struct TvEpisode {
    const TvShow* m_show{};            // ptr to parent TV show
    unsigned short m_numberOverall{};  // overall episode number
    unsigned short m_season{};         // season number
    unsigned short m_numberInSeason{}; // number in the season
    std::string m_airDate{};           // date
    unsigned int m_length{};           // in seconds
    std::string m_title{};             // title
    std::string m_summary{};           // summary

    // intialize
    TvEpisode(const TvShow* show, unsigned short numberOverall, unsigned short season,
              unsigned short numberInSeason, const std::string& airDate,
              unsigned int length, const std::string& title,
              const std::string& summary)
        : m_show(show), m_numberOverall(numberOverall), m_season(season),
          m_numberInSeason(numberInSeason), m_airDate(airDate), m_length(length),
          m_title(title), m_summary(summary) {}
};

class TvShow : public MediaItem {
    std::string m_id;                     // id
    std::vector<TvEpisode> m_episodes;    // list of eps

    // private constructor
    TvShow(const std::string& id, const std::string& title, const std::string& summary, unsigned short year)
        : MediaItem(title, summary, year), m_id(id) {}

public:
    // display func
    void display(std::ostream& out) const override;

    // create from csv
    static TvShow* createItem(const std::string& strShow);


    // add episode full functionality
    template <typename Collection_t>
    static void addEpisode(Collection_t& col, const std::string& strEpisode) {
        if (strEpisode.empty() || strEpisode[0] == '#') {
            throw "Not a valid episode.";
        }

        std::istringstream stream(strEpisode);
        std::string id, airDate, lengthStr, title, summary, seasonStr;
        unsigned short numberOverall, season = 1, numberInSeason;

        // parse time strings in hh:mm:ss
        auto parseTime = [](const std::string& timeStr) -> unsigned int {
            unsigned int hours = 0, minutes = 0, seconds = 0;
            char delimiter; // For ':'
            std::istringstream timeStream(timeStr);
            timeStream >> hours >> delimiter >> minutes >> delimiter >> seconds;
            return hours * 3600 + minutes * 60 + seconds;
        };

        // parse csv 
        std::getline(stream, id, ',');               // id
        stream >> numberOverall;                     // ep no
        stream.ignore();                             // ignore comma
        std::getline(stream, seasonStr, ',');        // season num
        stream >> numberInSeason;                    // ep num in season
        stream.ignore();                             // ignore comma
        std::getline(stream, airDate, ',');          // date
        std::getline(stream, lengthStr, ',');        // length string
        std::getline(stream, title, ',');            // title
        std::getline(stream, summary);               // summary

        // trim whitespaces
        trim(id);
        trim(seasonStr);
        trim(airDate);
        trim(lengthStr);
        trim(title);
        trim(summary);

        // handle missing season number
        if (seasonStr.empty()) {
            season = 1; // def to 1
        } else {
            try {
                season = std::stoi(seasonStr); // convert to int if not empty
            } catch (...) {
                season = 1;
            }
        }

        // convert length to seconds
        unsigned int lengthInSeconds = parseTime(lengthStr);

        // find matching tv show by id
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
            throw "show not found for episode.";
        }

        // add ep to tv show
        TvEpisode episode = {matchingShow, numberOverall, season, numberInSeason, airDate, lengthInSeconds, title, summary};
        matchingShow->m_episodes.push_back(episode);
    }

    // avg episode length
    double getEpisodeAverageLength() const;

    // >60m 
    std::list<std::string> getLongEpisodes() const;
};

} 

#endif
