#include "Coordinates.h"
double Coordinates::Latitude()
{
  return latitude;
}
double Coordinates::Longitude()
{
  return longitude;
}
void Coordinates::Longitude(double longi)
{
longitude=longi;
}
void Coordinates::Latitude(double lati)
{
latitude=lati;
}
Coordinates::Coordinates(double lati, double longi)
{
  longitude=longi;
  latitude=lati;
}
Coordinates::Coordinates()
{
  longitude=0;
  latitude=0;
}
void Coordinates::Set(double lati, double longi)
{
  latitude=lati;
  longitude=longi;
}