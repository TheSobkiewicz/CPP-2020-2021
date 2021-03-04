#include<string>
#include <iostream>
#include"MapPoint.h"
using namespace std;

MapPoint *construct(string name,double latitude , double longitude )
{
 MapPoint *a=new MapPoint;
 a->longitude=longitude;
 a->latitude=latitude;
 a->name=name;
 return a;
}
void print(MapPoint *a)
{
cout<<"Dla "<<a->name<<" to "<<a->longitude<<" i "<<a->latitude<<"."<<endl;
}
void print(const MapPoint *a)
{
cout<<"Dla "<<a->name<<" to "<<a->longitude<<" i "<<a->latitude<<"."<<endl;
}
void movePoint(MapPoint *a,double s1,double s2)
{
a->longitude+=s1;
a->latitude+=s2;
}