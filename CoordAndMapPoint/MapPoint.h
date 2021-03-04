#pragma once 
#include <iostream>
#include "Coordinates.h"
static int number=0;
class MapPoint
{
   Coordinates cord;
  std::string name;
  friend double surfaceTriangleArea(MapPoint a, MapPoint b, MapPoint c);
  public:
   MapPoint(std::string data="",double lati=0, double longi=0);
   Coordinates GetCoordinates()const;
   Coordinates &GetCoordinates();
  void Print();
  void SetId(std::string data);
  static int NumberOfPoints();
  
};
double surfaceTriangleArea(MapPoint a, MapPoint b, MapPoint c);