#include "MapPoint.h"
MapPoint::MapPoint(std::string data,double lati, double longi)
{
 name=data;
 cord=Coordinates(lati,longi);
 number++;
}
Coordinates MapPoint::GetCoordinates()const
{
  return cord;
}
Coordinates& MapPoint::GetCoordinates()
{
  return cord;
}
void MapPoint::Print()
{
   std::cout<< "Point: "<<name<< " ("<< cord.Latitude()<< ","<<cord.Longitude() << ")"<<std::endl;

}
void MapPoint::SetId(std:: string data)
{
  name=data;
}
int MapPoint::NumberOfPoints()
{
  return number;
}
double surfaceTriangleArea(MapPoint a, MapPoint b, MapPoint c)
{
  double x1=a.GetCoordinates().Latitude();
  double x2=b.GetCoordinates().Latitude();
  double x3=c.GetCoordinates().Latitude();
  double y1=a.GetCoordinates().Longitude();
  double y2=b.GetCoordinates().Longitude();
  double y3=c.GetCoordinates().Longitude();

return  ((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1))/2;
}

