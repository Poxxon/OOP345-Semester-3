#include "team.h"
#include <iostream>
#include <string>

using namespace std;

namespace seneca {

void Team::addMember(const Character *c) {
  if (findMember(c->getName()) != -1) {
    return;
  }

  // Resize the team if capacity is full
  if (m_size == m_capacity) {
    m_capacity *= 2;
    Character **temp = new Character *[m_capacity];
    for (size_t i = 0; i < m_size; ++i) {
      temp[i] = m_team[i];
    }
    delete[] m_team;
    m_team = temp;
  }

  m_team[m_size++] = c->clone();
}

// Removes a character from the team based on their name.
void Team::removeMember(const string &c) {
  int index = findMember(c);
  if (index == -1) {
    return;
  }

  delete m_team[index]; // Free memory for the removed character

  // Shift the remaining team members
  for (size_t i = index; i < m_size - 1; ++i) {
    m_team[i] = m_team[i + 1];
  }
  m_size--;
}

// Operator overload for accessing team members by index.
Character *Team::operator[](size_t idx) const {
  if (idx >= m_size) {
    return nullptr;
  }
  return m_team[idx];
}

// Displays the names of all team members.
void Team::showMembers() const {
  if (m_capacity == 0) {
    cout << "No team.\n";
    return;
  }

  cout << "[Team] " << m_name << "\n";
  for (size_t i = 0; i < m_size; ++i) {
    cout << "    " << i + 1 << ": " << *m_team[i] << "\n";
  }
}

} // namespace seneca