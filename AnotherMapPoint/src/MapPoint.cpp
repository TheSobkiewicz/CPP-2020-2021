#include "MapPoint.h"
MapPoint::~MapPoint()
{
  std::cout<<"Usuwanie "<<name<<std::endl;
}
MapPoint::MapPoint(std::string data,double longi, double lati)
{
  name=data;
  latitude=lati;
  longitude=longi;
  if(lati<0)
  {
    latchar='S';
  }
  else
  {
    latchar='N';
  }
  if(longi<0)
  {
    longchar='W';
  }
  else
  {
    longchar='E';
  }
}
MapPoint::MapPoint(std::string data, double longi, char ch1, double lati,char ch2)
{
  name=data;
  longchar=ch1;
  longitude=ch1=='E'?longi:-longi;
  
  latitude='N'?lati:-lati;
  latchar=ch2;
}
void MapPoint::print()const
{
  std::cout<<"Wspolrzedne dla "<<name<<": "<<fabs(longitude)<<longchar<<", "<<fabs(latitude)<<latchar<<".\n";
}
void MapPoint::movePoint(const double longshift, const double latshift)
{
  longitude=longitude+longshift;
  latitude=latitude+latshift;
 latchar=latitude>0?'N':'S';
 longchar=longitude>0?'E':'W';
}
MapPoint MapPoint::closestFrom(MapPoint *a, MapPoint *b)
{
  if(hypot(longitude-a->longitude, latitude-a->latitude)<hypot(longitude - b->longitude, latitude-b->latitude))return *a;
  else return *b;
}
std::string MapPoint::getName()const
{
  return name;
}
MapPoint inTheMiddle(MapPoint *a, MapPoint *b,std::string name)
{
return MapPoint(name,(a->longitude+b->longitude)/2,(a->latitude+b->latitude)/2);
}