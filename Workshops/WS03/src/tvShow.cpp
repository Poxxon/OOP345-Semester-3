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
namespace seneca {

// Display function for TV shows and episodes
void TvShow::display(std::ostream& out) const {
    // Check if table view is enabled in settings
    if (g_settings.m_tableView) {
        out << "S | ";  // Prefix for TV shows
        out << std::left << std::setfill('.');
        out << std::setw(50) << this->getTitle() << " | "; // Title
        out << std::right << std::setfill(' ');
        out << std::setw(2) << this->m_episodes.size() << " | "; // Number of episodes
        out << std::setw(4) << this->getYear() << " | ";         // Release year
        out << std::left;

        // Display summary with optional truncation
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
    } else {
        // Detailed view formatting
        size_t pos = 0;
        out << this->getTitle() << " [" << this->getYear() << "]\n"; // Title and year
        out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << '\n';

        // Chunked display of the summary
        while (pos < this->getSummary().size()) {
            out << "    " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth) << '\n';
            pos += g_settings.m_maxSummaryWidth;
        }

        // Display each episode
        for (auto& item : m_episodes) {
            out << std::setfill('0') << std::right;
            out << "    S" << std::setw(2) << item.m_season
                << "E" << std::setw(2) << item.m_numberInSeason << ' ';
            if (!item.m_title.empty()) {
                out << item.m_title << '\n'; // Episode title
            } else {
                out << "Episode " << item.m_numberOverall << '\n'; // Default label
            }

            // Chunked display of the episode summary
            pos = 0;
            while (pos < item.m_summary.size()) {
                out << "            " << item.m_summary.substr(pos, g_settings.m_maxSummaryWidth - 8) << '\n';
                pos += g_settings.m_maxSummaryWidth - 8;
            }
        }
        out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << std::setfill(' ') << '\n';
    }
}

// Create a TV show object from a CSV-formatted string
TvShow* TvShow::createItem(const std::string& strShow) {
    if (strShow.empty() || strShow[0] == '#') {
        throw "Not a valid show."; // Skip empty or comment lines
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

    // Convert year to appropriate type
    unsigned short year = std::stoi(yearStr);

    return new TvShow(id, title, summary, year);
}

// Calculate the average length of all episodes
double TvShow::getEpisodeAverageLength() const {
    if (m_episodes.empty()) {
        return 0.0; // No episodes
    }

    // Sum up all episode lengths using accumulate
    auto totalLength = std::accumulate(m_episodes.begin(), m_episodes.end(), 0u,
        [](unsigned int sum, const TvEpisode& episode) {
            return sum + episode.m_length; // Add length to sum
        });

    return static_cast<double>(totalLength) / m_episodes.size(); // Compute average
}

// Retrieve titles of episodes longer than 60 minutes
std::list<std::string> TvShow::getLongEpisodes() const {
    std::list<std::string> longEpisodes;

    // Iterate through episodes and filter by length
    std::for_each(m_episodes.begin(), m_episodes.end(),
        [&](const TvEpisode& episode) {
            if (episode.m_length >= 3600) { // 3600 seconds = 1 hour
                longEpisodes.push_back(episode.m_title);
            }
        });

    return longEpisodes;
}

} // namespace end
