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

#include "tvShow.h"
#include <sstream>
#include <iomanip>
#include <numeric>
namespace seneca {

// Display TV show details, including episodes
void TvShow::display(std::ostream& out) const {
    if (g_settings.m_tableView) { // Table view formatting
        out << "S | ";
        out << std::left << std::setfill('.');
        out << std::setw(50) << this->getTitle() << " | "; // Show title
        out << std::right << std::setfill(' ');
        out << std::setw(2) << this->m_episodes.size() << " | "; // Episode count
        out << std::setw(4) << this->getYear() << " | ";         // Release year
        out << std::left;

        // Show summary
        if (g_settings.m_maxSummaryWidth > -1) {
            if (static_cast<short>(this->getSummary().size()) <= g_settings.m_maxSummaryWidth) {
                out << this->getSummary();
            } else {
                out << this->getSummary().substr(0, g_settings.m_maxSummaryWidth - 3) << "...";
            }
        } else {
            out << this->getSummary();
        }
        out << std::endl;
    } else { // Detailed view formatting
        size_t pos = 0;
        out << this->getTitle() << " [" << this->getYear() << "]\n";
        out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << '\n';

        // Display summary in chunks
        while (pos < this->getSummary().size()) {
            out << "    " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth) << '\n';
            pos += g_settings.m_maxSummaryWidth;
        }

        // Display episodes
        for (const auto& episode : m_episodes) {
            out << std::setfill('0') << std::right;
            out << "    S" << std::setw(2) << episode.m_season << "E" << std::setw(2) << episode.m_numberInSeason << ' ';

            if (!episode.m_title.empty()) {
                out << episode.m_title << '\n';
            } else {
                out << "Episode " << episode.m_numberOverall << '\n';
            }

            // Display episode summary in chunks
            pos = 0;
            while (pos < episode.m_summary.size()) {
                out << "            " << episode.m_summary.substr(pos, g_settings.m_maxSummaryWidth - 8) << '\n';
                pos += g_settings.m_maxSummaryWidth - 8;
            }
        }
        out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << std::setfill(' ') << '\n';
    }
}

// Create a TV show from a CSV-formatted string
TvShow* TvShow::createItem(const std::string& strShow) {
    if (strShow.empty() || strShow[0] == '#') {
        throw "Not a valid show."; // Invalid input
    }

    std::istringstream stream(strShow);
    std::string id, title, yearStr, summary;

    // Parse CSV fields
    std::getline(stream, id, ',');
    std::getline(stream, title, ',');
    std::getline(stream, yearStr, ',');
    std::getline(stream, summary);

    // Trim whitespace
    trim(id);
    trim(title);
    trim(yearStr);
    trim(summary);

    // Convert year string to unsigned short
    unsigned short year = std::stoi(yearStr);

    return new TvShow(id, title, summary, year);
}

// Calculate the average length of episodes in seconds
double TvShow::getEpisodeAverageLength() const {
    if (m_episodes.empty()) {
        return 0.0;
    }

    // Use std::accumulate to calculate total length
    auto totalLength = std::accumulate(m_episodes.begin(), m_episodes.end(), 0u,
        [](unsigned int sum, const TvEpisode& episode) {
            return sum + episode.m_length;
        });

    return static_cast<double>(totalLength) / m_episodes.size(); // Return average
}

// Get titles of episodes longer than 60 minutes
std::list<std::string> TvShow::getLongEpisodes() const {
    std::list<std::string> longEpisodes;

    // Iterate through episodes to find those longer than 3600 seconds (60 minutes)
    std::for_each(m_episodes.begin(), m_episodes.end(),
        [&](const TvEpisode& episode) {
            if (episode.m_length >= 3600) {
                longEpisodes.push_back(episode.m_title);
            }
        });

    return longEpisodes;
}

} // namespace end
