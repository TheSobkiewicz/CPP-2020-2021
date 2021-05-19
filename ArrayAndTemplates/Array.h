#pragma once
#include <array>
#include <iostream>
#include "X.h"
template <int size, typename T>
class Array { // klasa reprezentujaca array dowolnego typu
  public:
  T& operator[](int i) { //getter i setter zwracajacy wartosc pod podanym indeksem
    return arr[i];
  }
  
  private:

  std::array<T,size> arr = {};


};
template <int size, typename T> // operator wypisujacy dla Array dowolnego typu
std::ostream& operator << (std::ostream &out, Array<size,T> &a) {
  for(int i=0; i< size; i++){
    out << a[i] << " "; 
  }
  return out;
}

template <int size>
std::ostream& operator << (std::ostream &out, Array<size,X> &a) { //operator wypisujacy dla Array zawierajacego obiekty klasy X
  for(int i=0; i< size; i++){
    out << a[i].get() << " "; 
  }
  return out;
}



template<int size>
class Array<size, X*> {//Klasa reprezentujaca array wskaźników na obiekty klasy X, funkcje jak w powyższej klasie, pamiec zostaje automatycznie zwolniona
  public:

  X*& operator[](int i) { //getter i setter dla podanego indeksu, nadpisanie istniejacego indeksu powoduje wyciek pamieci
    return arr[i];
  }

  ~Array() { 
    for(auto a: arr) {
      if(a) delete a;    
      }
  }
  
  private:

  std::array<X*,size> arr = {};
};

template <int size>
std::ostream& operator << (std::ostream &out, Array<size,X*> &a) {//operator wypisujacy dla Array zawierajacego *X
  for(int i=0; i< size; i++){
   if(a[i]) out << a[i]->get() << " "; 
  }
  return out;
}