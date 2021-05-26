#pragma once
#include <iostream>
class Person {//klasa reprezentujaca osoby
  public:
  Person() = default;
  Person(std::string n, bool gender):woman(gender), name(n){} //konstuktor przypisujacy imie i plec

  static Person kobieta(std::string n) { //metoda zwracajaca osobe płci żeńskiej o nazwie n
    return Person(n,true);
  }
  
  static Person mezczyzna(std::string n) { //metoda zwracajaca osobe płci meskiej o nazwie n
    return Person(n,false);
  }

  bool isWoman() const { //funkcja zwraca czy dana osoba jest kobieta
    return woman;
  }

  void print(std::ostream &os) const { // pomocnicza funkcja wypisujaca
    os << name << " " << (woman?"K":"M");

  }



  private:
  bool woman;
  std::string name;

};

std::ostream& operator << (std::ostream &os, const Person &a) { //operator wypisywania dla klasy Person
  a.print(os);
  return os;
}