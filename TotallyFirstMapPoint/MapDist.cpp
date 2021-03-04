#include "MapDist.h"
MapDist distance( MapPoint a, MapPoint b)
{
  MapDist fresh;//=new MapDist;
  fresh.latitude=a.latitude-b.latitude;
  fresh.longitude=a.longitude - b.longitude;
  return fresh;
}
double angularDistance(MapDist a)
{
  return sqrt(a.latitude*a.latitude+a.longitude*a.longitude);
}
MapPoint closestPlace(MapPoint*cel ,MapPoint*a,MapPoint*b)
{
 double a1=angularDistance(distance(*cel,*a));
 double b1=angularDistance(distance(*cel,*b));
 if(a1>=b1)return *a;
 else return *b;
}
std::string getName(MapPoint a)
{
return a.name;
}
MapPoint inTheMiddle(MapPoint *a, const MapPoint *b, std::string name)
{
MapPoint fresh;
fresh.longitude=(a->longitude+b->longitude)/2;
fresh.latitude=(a->latitude+b->latitude)/2;
fresh.name=name;
return fresh;
}
void clear(MapPoint *a,MapPoint *b, MapPoint *c)
{
delete (a);
delete (b);
delete (c);
}
void clear(const MapPoint *a)
{
  delete(a);
}