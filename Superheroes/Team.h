#pragma once
#include "Member.h"
#include <set>
#include <algorithm>
#include <functional>

class Team {  //klasa reprezentujaca druzyne bohaterow, nic nie jest dynamicznie alokowane, sama dba o pamiec
  public:
  void add(const Member &toAdd) { //funkcja dodajaca bohatera do druzyny
    crew.insert(toAdd);
  }

  void print(std:: ostream &o)const { //pomocnicza funkcja wypisujaca
    std::for_each(crew.begin(), crew.end(),[&](const Member &a){
      o<<a<<"\n";
    });
  }

  void kill(std::function<bool(const Member&)> f); // funkcja usuwa z druzyny bohaterow, spelniajacych warunek f



  Team operator -(const Team &a) const; // funkcja zwracajaca druzyne skladajaca sie z bohaterow wystepujacych jednoczesnie w druzynie na ktorej zostala wywolana i a
  Team operator +(const Team &a) const; // funkcja zwracajaca druzyne skladajaca sie z bohaterow wystepujacych  w druzynie na ktorej zostala wywolana lub a






  private:
  std::set<Member> crew;
};

std::ostream& operator<<(std::ostream& o, const Team& m);//operator wypisujacy