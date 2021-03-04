#pragma once
#include <string>
struct MapPoint
{
  double longitude=0;
  double latitude=0;
  std::string name; 
};
MapPoint *construct(std::string,double,double);
void print(MapPoint *a);
void print(const MapPoint *a);
void movePoint(MapPoint *a,double,double);