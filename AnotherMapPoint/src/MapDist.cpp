#include "MapDist.h"
MapDist::MapDist(MapPoint a, MapPoint b)
{
  longdiff=fabs(a.longitude-b.longitude);
  latdiff=fabs(a.latitude-b.latitude);
}
MapDist distance(MapPoint a,MapPoint b)
{
  return MapDist(a,b);
}
double MapDist::angularDistance()const
{
  return hypot(longdiff,latdiff);
}
double MapDist::getlatitude()const
{
  return latdiff;
}
double MapDist::getlongitude()const
{
  return longdiff;
}