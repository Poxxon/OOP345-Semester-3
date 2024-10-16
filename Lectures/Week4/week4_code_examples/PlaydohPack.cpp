// PlaydohPack.cpp
#include "Playdoh.h"
#include "PlaydohPack.h"

PlaydohPack::PlaydohPack() {
}

PlaydohPack::PlaydohPack(const char* nm, int dc, const char* dohs[]) 
  : name(nm), dohCount(dc)  {
  if (dohCount > 0) {
    playdohs = new Playdoh[dohCount];
    for (int i = 0; i < dohCount; ++i) {
      playdohs[i].setColour(dohs[i]);
      playdohs[i].setWeight(rand() % 10);
    }
  }
}

PlaydohPack::PlaydohPack(const PlaydohPack& src) {
  *this = src;
}

PlaydohPack& PlaydohPack::operator=(const PlaydohPack& src) {
  if (this != &src) {
    delete[] playdohs;
    playdohs = nullptr;
    name = src.name;
    dohCount = src.dohCount;
    if (src.playdohs && dohCount > 0) {
      playdohs = new Playdoh[dohCount];
      for (int i = 0; i < dohCount; ++i) {
        playdohs[i] = src.playdohs[i];
      }
    }
  }
  return *this;
}

std::ostream& PlaydohPack::display(std::ostream& os) const {
  os << "PlaydohPack\nName: " << name << std::endl;
  os << "Count: " << dohCount << std::endl;
  for (int i = 0; i < dohCount; ++i) {
    os << "#" << i + 1 << " "; 
    os << playdohs[i];
  }
  return os;
}

PlaydohPack::~PlaydohPack() {
  delete[] playdohs;
}

std::ostream& operator<<(std::ostream& os, const PlaydohPack& p) {
  return p.display(os);
}
