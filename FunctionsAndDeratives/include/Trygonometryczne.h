#pragma once 
#include <math.h>
class Sinus:public Fun{
static Fun* utworz(){return new Sinus;}
double wartosc(double x)const{return sin(x);};
};