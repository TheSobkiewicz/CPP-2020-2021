#pragma once
#include "Suma.h"
#include <cmath>
class Pierwiastek:public Algo{
public:
  Argumenty wykonaj(const Argumenty &data)const{//funkcja oblicza Pierwiastek dla kazdej wartosci argumentu adata
    Argumenty add(data.rozmiar());
    for(int i=0;i< data.rozmiar();i++ ){
      add(i,sqrt(data.getVal(i)));
    }
  return add;
  }
  Pierwiastek *sklonuj()const{//funkcja zwracajaca nowy obiekt klasy Pierwiastek
    return new  Pierwiastek();
  }
};