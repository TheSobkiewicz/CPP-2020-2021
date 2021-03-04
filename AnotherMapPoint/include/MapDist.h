#pragma once
#include<iostream>
#include "MapPoint.h"
class MapPoint;
class MapDist
{
friend MapDist distance(MapPoint a, MapPoint b);
double longdiff;
double latdiff;
public: 
  MapDist(MapPoint a, MapPoint b);//konstruktor klasy, przypisuje wartość a do latdiff a b do longdiff
  //void print();//funkcja wypisujaca 
  double angularDistance()const;
  double getlatitude()const;
  double getlongitude()const;
};
MapDist distance(MapPoint a, MapPoint b);
