#pragma once
#include <iostream>
class MapDistance
{
double longidiff;
double latidiff;
public:
  MapDistance(double a, double b);//konstruktor klasy MapDistance, a=różnica parametrów longitude, b = różnica parametrów latitude
  void print();//wypisujemy odległość między punktami
};
