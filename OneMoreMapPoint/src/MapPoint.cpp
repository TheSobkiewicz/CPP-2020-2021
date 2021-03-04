#include "MapPoint.h"
#include <cmath>
void MapPoint::print()
{
std::cout<<"Point: ("<<latitude<<","<<longitude<<")\n";
}
void MapPoint::set_coordinates(double a, double b)
{
longitude=b;
latitude=a;
}
MapDistance MapPoint::distance(MapPoint &a){
 MapDistance dist(a.longitude-longitude,a.latitude-latitude);
 return dist;
}
MapPoint MapPoint::half_way_to(MapPoint &a){
  MapPoint somewhere;
  somewhere.set_coordinates((longitude+a.longitude)/2, (latitude +a.latitude)/2);
return somewhere;
}
void MapPoint::set_latitude(double b)
{
latitude=b;
}
void MapPoint::set_longitude(double a)
{
longitude=a;
}
MapPoint MapPoint::closest(MapPoint &a, MapPoint &b)
{
if(sqrt(longitude-a.longitude)*(longitude-a.longitude)+(latitude-a.latitude)*(latitude-a.latitude)>sqrt(longitude-b.longitude)*(longitude-b.longitude)+(latitude-b.latitude)*(latitude-b.latitude)) return b;
else return a;
}