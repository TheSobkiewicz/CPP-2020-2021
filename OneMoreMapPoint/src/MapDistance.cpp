#include "MapDistance.h"
MapDistance::MapDistance(double a, double b)
{
  longidiff=a;
  latidiff=b;
}
void MapDistance::print()
{
  std::cout<<"Point: ("<<latidiff<<","<<longidiff<<")\n";
}