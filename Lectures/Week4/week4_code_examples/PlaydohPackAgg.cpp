// PlaydohPackAgg.cpp
#include "Playdoh.h"
#include "PlaydohPackAgg.h"

PlaydohPackAgg::PlaydohPackAgg() {}

PlaydohPackAgg::PlaydohPackAgg(const char* nm) : name(nm) {}

PlaydohPackAgg::~PlaydohPackAgg() {
  std::cout << "In PlaydohPackAgg destr" << std::endl;
}

std::ostream& PlaydohPackAgg::display(std::ostream& os) const {
  os << "PlaydohPack\nName: " << name << std::endl;
  os << "Count: " << dohCount << std::endl;
  for (int i = 0; i < dohCount; ++i) {
    os << "#" << i + 1 << " "; 
    os << *playdohs[i];
  }
  return os; 
}

PlaydohPackAgg& PlaydohPackAgg::operator+=(const Playdoh& src){
  if (dohCount < packsize) {
    playdohs[dohCount] = &src;
    dohCount++;
  }
  return *this;
}

PlaydohPackAgg& PlaydohPackAgg::operator-=(const Playdoh& src){
  bool found = false;
  int i = 0;
  for (; i < dohCount && !found; ++i) {
    if (*playdohs[i] == src) {
      found = true;
    }
  }
  if (found) {
    for (; i < dohCount; ++i)
      playdohs[i - 1] = playdohs[i]; // shift the playdohs down
    if (dohCount > 0) {
      playdohs[dohCount - 1] = nullptr; // set the last one to nullptr
      dohCount--;
    }
  }
  return *this;
}

std::ostream& operator<<(std::ostream& os, const PlaydohPackAgg& p) {
  return p.display(os);
}
