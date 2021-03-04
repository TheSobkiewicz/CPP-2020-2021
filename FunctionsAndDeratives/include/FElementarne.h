#pragma once
#include "Fun.h"
class Liniowa:public Fun{
public:
Liniowa(){
  a1=0;
  b1=0;
}
  static Liniowa* utworz(){return new Liniowa;}
  double wartosc(double x)const{ 
  return a1*x+b1;
  }
  Liniowa* a(double x)
  {a1=x;return this;}
  Liniowa* b(double x){b1=x;return this;}
  protected:
  double a1;
  double b1;
  
};


class Kwadratowa:public Liniowa{
public:
  Kwadratowa(){
    a1=0;
    b1=0;
    c1=0;
  }
  static Kwadratowa* utworz(){return new Kwadratowa;}
  double wartosc(double x)const{ 
    return a1*x*x+b1*x+c1;
  }
  Kwadratowa* a(double x){a1=x;return this;}
  Kwadratowa* b(double x){b1=x;return this;}
  Kwadratowa* c(double x){c1=x;return this;}
private:
  double c1;

};