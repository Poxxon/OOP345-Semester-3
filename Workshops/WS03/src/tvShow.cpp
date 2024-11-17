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


  // display func
  void TvShow::display(std::ostream& out) const
  {
    if (g_settings.m_tableView)
    {
      out << "S | ";
      out << std::left << std::setfill('.');
      out << std::setw(50) << this->getTitle() << " | ";
      out << std::right << std::setfill(' ');
      out << std::setw(2) << this->m_episodes.size() << " | ";
      out << std::setw(4) << this->getYear() << " | ";
      out << std::left;
      if (g_settings.m_maxSummaryWidth > -1)
      {
        if (static_cast<short>(this->getSummary().size()) <= g_settings.m_maxSummaryWidth)
          out << this->getSummary();
        else
          out << this->getSummary().substr(0, g_settings.m_maxSummaryWidth - 3) << "...";
      }
      else
        out << this->getSummary();
      out << std::endl;
    }
    else
    {
      size_t pos = 0;
      out << this->getTitle() << " [" << this->getYear() << "]\n";
      out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << '\n';
      while (pos < this->getSummary().size())
      {
        out << "    " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth) << '\n';
        pos += g_settings.m_maxSummaryWidth;
      }
      for (auto& item : m_episodes)
      {
        out << std::setfill('0') << std::right;
        out << "    " << 'S' << std::setw(2) << item.m_season
          << 'E' << std::setw(2) << item.m_numberInSeason << ' ';
        if (item.m_title != "")
          out << item.m_title << '\n';
        else
          out << "Episode " << item.m_numberOverall << '\n';

        pos = 0;
        while (pos < item.m_summary.size())
        {
          out << "            " << item.m_summary.substr(pos, g_settings.m_maxSummaryWidth - 8) << '\n';
          pos += g_settings.m_maxSummaryWidth - 8;
        }
      }
      out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << ""
        << std::setfill(' ') << '\n';
    }
  }


  // create tvshow from csv
  TvShow* TvShow::createItem(const std::string& strShow) {
      if (strShow.empty() || strShow[0] == '#') {
          throw "Not a valid show.";
      }

      std::istringstream stream(strShow);
      std::string id, title, yearStr, summary;

      // parse csv
      std::getline(stream, id, ',');
      std::getline(stream, title, ',');
      std::getline(stream, yearStr, ',');
      std::getline(stream, summary);

      // trim whitespaces
      trim(id);
      trim(title);
      trim(yearStr);
      trim(summary);

      // convert to appropiate type
      unsigned short year = std::stoi(yearStr);

      return new TvShow(id, title, summary, year);
  }


  // avg length
  double TvShow::getEpisodeAverageLength() const {
      if (m_episodes.empty()) {
          return 0.0;
      }
      // use accumulate to calc total length of all eps
      auto totalLength = std::accumulate(m_episodes.begin(), m_episodes.end(), 0u,
          [](unsigned int sum, const TvEpisode& episode) {
              // add to running sum
              return sum + episode.m_length;
          });
      // divide by num of eps and return as double
      return static_cast<double>(totalLength) / m_episodes.size();
  }


  // get eps greater than 60m
  std::list<std::string> TvShow::getLongEpisodes() const {
      std::list<std::string> longEpisodes;

      // for each iterate thru all eps and check length
      std::for_each(m_episodes.begin(), m_episodes.end(),
          [&](const TvEpisode& episode) {      // <------- tried not using capture by ref but couldnt figure it out :( 
              if (episode.m_length >= 3600) {  // only episodes greater than 1h (60sx60m)
                  longEpisodes.push_back(episode.m_title);
              }
          });

      return longEpisodes;
  }




  }  
