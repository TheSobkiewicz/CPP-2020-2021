#include "pasture.h"
Pasture::Pasture(double v, int sheeps){
  pole=v*v;
  tab=new bool[sheeps];
  size=sheeps;
for(int i=0;i<sheeps;i++){
  tab[i]=rand()%2;
}
}
Pasture::~Pasture(){


}
Pasture::Pasture(){
  pole=0;
  tab=nullptr;
  size=0;
}

Pasture Pasture::operator*(double a){
Pasture add;
add.size=size;
add.pole=pole*a;
add.tab=tab;
return add;
}
Pasture Pasture::operator+(const Pasture &a){
  Pasture add;
  add.pole=pole+a.pole;
  add.size=size+a.size;
  add.tab=new bool[add.size];
  for(int i=0;i<size;i++){
    add.tab[i]=tab[i];
  }
   for(int i=0;i<a.size;i++){
    add.tab[size+i]=a.tab[i];
  }
  return add;
}
Pasture Pasture::operator*=(double a){
  Pasture add;
  add.size=size;
add.pole=pole*a;
add.tab=tab;
return add;
}

std::ostream& operator<<(std::ostream& os, const Pasture past)
{
  os<<"Pole: "<<past.pole<<", owce:";
  for(int i=0;i<past.size;i++){
    os<<" "<<past.tab[i];
  }
  os<<"\n";
  return os;
}
Pasture operator*(double a, Pasture past){
    Pasture add;
    add.size=past.size;
add.pole=past.pole*a;
add.tab=past.tab;
return add;
}
