
#pragma once
#include <iostream>
#include <vector>
class Argumenty{//klasa przedstawiajaca grupe argumentow
public:

Argumenty (int n);//konstruktor ustalajacy wielkosc wektora na n

friend std::ostream& operator << (std::ostream &a,const  Argumenty &arg);// deklaracja przyjazni z operatorem <<

int rozmiar () const {
  return vec.size();
}//getter dla rozmiaru

double operator[] (int i)const {
  return vec[i];
}//getter dla wartości vec[i]

Argumenty& operator() (int i, double data);//operator przypisujący wartość data do vec[i]
static Argumenty pojedynczy (double data);//funckja zwracajaca obiekt klasy Argumenty z wartascia data
private:
  std::vector<double> vec;
};
std::ostream& operator << (std::ostream &a,const Argumenty &arg);//operator wypisujacy dla obiektow klasy Argumenty