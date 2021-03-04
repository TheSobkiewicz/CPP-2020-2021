#pragma once 
#include <iostream>
#include<math.h>
class Vector{

public:
  Vector(int s);//konsturktor domyślny
  Vector(const Vector &org);//konsturktor kopiujący
  Vector( Vector &&org);//konsturktor przenoszący
  ~Vector();//destruktor
  int &at(int i);//funkcja zwracajaca referencje na tab[i]
  void print(std::string data)const;//funkcja wypisujaca 
  static double dot(const Vector &a,const Vector &b);//Funkcja zwracajaca iloczyn skalarny wektora a i b
  operator double()const;//operator konwersji na double, zwraca norme wektora
  double norm()const;//funkcja normalizujaca wektor
  static Vector sum(const Vector &a,const Vector &b);//funkcja zwracajaca wektor bedacy suma a i b
  static Vector sum(const Vector &a,int b);//funkcja zwracajaca wektor bedacy wynikiem dodana b do kazdej wspolrzednej w a.tab

private:;
  int size;
  int *tab;
};

