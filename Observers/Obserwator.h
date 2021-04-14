#pragma once
#include <iostream>
class Obserwator{
  public:
virtual void doYourJob( int x ) = 0;//czysto wirtualna funkcja wywoływana przez obserwowanych w funkcji noweDanenadeszły, odpowiada za działanie każdego z obserwatorów przedłużajacych tę klasę


};

class ObserwatorLicznik : public Obserwator {//obserwator sumujący dane przechodzace przez obserwowanych
  public:
void doYourJob( int x );// Dodaje zmienna x zmiennej suma za kazdym razem gdy w obserwowanych obiektach zostaje wywołana funckja noweDanenadeszły(x).

int suma();//zwraca wartosc zmiennej suma
private:
int sum = 0;

};

class  ObserwatorWypisywacz : public Obserwator {//obserwator wypisujacy dane przechodzace przez obserwowanych
  public:
void doYourJob( int x );//wypisuje wartosc x za kazdym razem gdy w obserwowanych obiektach zostaje wywołana funckja noweDanenadeszły(x).


};