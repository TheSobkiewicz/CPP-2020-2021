#pragma once
#include "Argumenty.h"
class Algo{
  public:
virtual ~Algo(){}//wirtualny konstruktor żeby ominąć błędy kompilatora
virtual Argumenty wykonaj(const Argumenty &data)const{//wirtualna funkcja przyjmujaca Argumenty data
  return data;
}
virtual Algo *sklonuj()const{//wirtualna funkcja zwracajaca nowy obiekt tej instancjji
  return new  Algo();
}

};

class Suma:public Algo{
Argumenty wykonaj(const Argumenty &data)const{//funckja zwracajaca sume wszystkich wartosci w data
  double s=0;
  int size=data.rozmiar();
  for(int i=0;i<size;i++){
      s+=data.getVal(i);
  }
  Argumenty add(1);
  add(0,s);

  return add;
}
Suma *sklonuj()const{//funkcja zwracajaca nowy obiekt klasy Suma
  return new  Suma();
  }
};