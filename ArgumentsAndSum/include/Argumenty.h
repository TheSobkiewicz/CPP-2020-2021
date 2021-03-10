#include <iostream>
#pragma once
class Argumenty{//klasa przedstawiajaca grupe argumentow
public:
void print(std::string data,std::ostream &a=std::cout)const;//funkcja wypisująca
int rozmiar()const{return size;}//getter dla rozmiaru
double getVal(int i)const{return tab[i];}//getter dla wartości tab[i]
Argumenty(int a);//konstruktor
~Argumenty();//destruktor
Argumenty& operator()(int i, double data);//operator przypisujący wartość data do tab[i]

private:
  int size;
  double * tab;
};