#pragma once
#include "Person.h"
#include <functional>
#include <list>
#include <initializer_list>
template < typename T>
class QKolejka { // klasa reprezentujaca listę posortowaną wedlug podanej przy inicjalizacji funkcji
  public:
  typedef typename std::list<T>::const_reverse_iterator const_reverse_iterator;
  typedef typename std::list<T>::const_iterator const_iterator;
  QKolejka(std::function<int(T)> fun): comp(fun){}// konstruktor przyjmujacy  funkcje
  
  void dodaj(const T &element) { //funkcja dodajaca element do listy zgodnie z kolejnoscia
    if(ls.empty()) {
      ls.push_front(element);
      return;
    } 
    for(auto a=ls.begin(); a!= ls.end(); ++a ) {
      if(comp(*a)>comp(element)) {
        ls.insert(a,element);
        return;
      } 
      
    }
    ls.push_back(element);
  }

  void dodaj(std::initializer_list<T> list) {//funckja dodajaca wiele elementów zgodnie z kolejnoscia
      for(auto a : list ) {
        dodaj(a);
      }
  }


  const_iterator begin()const { // funkcje przeznaczone dla dzialania petli for range, zwracaja iteratory
    return ls.begin();
  }
  const_iterator end()const {
    return ls.end();
  }
  const_reverse_iterator rbegin()const {// funkcje zwracajace iteratory odwrotne

    return ls.rbegin();
  }
  const_reverse_iterator rend()const {
    return ls.rend();
  }


  private:
  std::list<T> ls;
  std::function<int(T)> comp;// funkcja wedle której bedziemy sortowac liste

};