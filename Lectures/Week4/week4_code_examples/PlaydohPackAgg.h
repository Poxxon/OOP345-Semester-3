// PladohPackAgg.h
#pragma once

#include <iostream>

class Playdoh;

const int packsize = 6;

class PlaydohPackAgg {
  std::string name{ "Unknown"};
  int dohCount{ 0 };
  const Playdoh* playdohs[packsize]{}; // array of ptrs

public:
  PlaydohPackAgg();
  PlaydohPackAgg(const char* nm);
  ~PlaydohPackAgg();

  std::ostream& display(std::ostream& os) const;

  PlaydohPackAgg& operator+=(const Playdoh& src);
  PlaydohPackAgg& operator-=(const Playdoh& src);

};

std::ostream& operator<<(std::ostream& os, const PlaydohPackAgg& p);
