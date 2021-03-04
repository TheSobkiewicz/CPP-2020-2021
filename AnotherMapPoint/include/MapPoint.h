#pragma once
#include <iostream>
#include<math.h>
#include "MapDist.h"
class MapDist;
class MapPoint//klasa reprezentująca punkt na mapie
{
  friend class MapDist;
  std::string name; 
  double latitude;
  char latchar; 
  double longitude;
  char longchar;
 friend MapPoint inTheMiddle(MapPoint *a, MapPoint *b,std::string name);
  public: 
  ~MapPoint();
  MapPoint(std::string data,double longi, double lati);
  MapPoint(std::string data, double longi, char ch1, double lati,char ch2);
  MapPoint closestFrom(MapPoint *a, MapPoint *b);
  std::string getName()const;
  
  void print()const;//Funkcja wypisująca wspólrzędne punktu
  void movePoint(const double longshift, const double latshift);
};
MapPoint inTheMiddle(MapPoint a, MapPoint b,std::string name);