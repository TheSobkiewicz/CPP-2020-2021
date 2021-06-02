#pragma once
#include <string>
#include <iostream>

struct Member { //klasa reprezentujaca czlonkow druzyny i ich statystyki
  Member(const std::string& n) : m_name(n) {}
  const std::string& name() const { return m_name; } // gettery dla poszczegolnych statystyk
  Member& power(int p) { m_power = p; return *this; }
  Member& magic(int p) { m_magic = p; return *this; }
  Member& health(int p) { m_health = p; return *this; }
  int power() const { return m_power; }
  int magic() const { return m_magic; }
  int health() const { return m_health; }

  bool operator < (const Member &a) const { // operator < potrzebny do umieszczenia obiektów tej klasy w pojemnikach sortowanych
    return m_name < a.m_name;
  }
  
  std::string m_name;
  int m_power;
  int m_magic;
  int m_health;
};


inline std::ostream& operator<<(std::ostream& o, const Member& m) { //operator wypisujacy
  o << m.name()
    << " power:" << m.power()
    << " magic:" << m.magic()
    << " health:" << m.health();
  return o;
}
