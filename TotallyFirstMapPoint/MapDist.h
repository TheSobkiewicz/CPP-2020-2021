#pragma once
#include"MapPoint.h"
#include<cmath>
struct MapDist
{
  double longitude=0;
  double latitude=0;
};
MapDist distance(MapPoint, MapPoint);
double angularDistance(MapDist);
MapPoint closestPlace(MapPoint*,MapPoint*,MapPoint*);
std::string getName(MapPoint);
MapPoint inTheMiddle(MapPoint*, const MapPoint*, std::string);
void clear(MapPoint*,MapPoint*,MapPoint*);
void clear(const MapPoint*);