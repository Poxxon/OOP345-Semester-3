// PlaydohPack.h
#pragma once

#include <iostream>
#include <string>

class Playdoh;

class PlaydohPack {
  std::string name{};
  int dohCount{0};
  Playdoh* playdohs{ nullptr };

public:
  PlaydohPack();
  PlaydohPack(const char* nm, int dc, const char* dohs[]);
  PlaydohPack(const PlaydohPack& src);
  PlaydohPack& operator=(const PlaydohPack& src);

  std::ostream& display(std::ostream& os) const;

  ~PlaydohPack();
};

std::ostream& operator<<(std::ostream& os, const PlaydohPack& p);
