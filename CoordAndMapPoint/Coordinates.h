#pragma once
#include <iostream>
class Coordinates
{
  double latitude;
  double longitude;
  public:
  Coordinates(double longi, double lati);
  Coordinates();
  double Latitude();
  double Longitude();
   void Latitude(double lati);
  void Longitude(double longi);
  void Set(double lati,double longi);
};