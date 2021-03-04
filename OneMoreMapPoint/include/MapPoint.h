#pragma once 
#include <iostream>
#include "MapDistance.h"
class MapPoint {
  double longitude;
  double latitude;
  public :
    void set_coordinates(double a, double b);//ustawiamy współrzędne punktu, a= nowa longitude, b=nowe latitude
    void set_longitude(double a);//ustawiamy wartośc longitude punktu na którym zostało wywołane  na b
    void set_latitude(double b);//ustawiamy wartośc latitude punktu na którym zostało wywołane  na b
    void print();//wypisujemy współrzędne punktu
    MapPoint closest(MapPoint &a, MapPoint &b);//sprawdzamy który z punktów - a czy b leży bliżej punktu na którym została wywołana funkcja
    MapPoint half_way_to(MapPoint &a);//zwraca punkt leżący dokładnie między punktem na którym została wywołana funkcja a punktem a
    MapDistance distance(MapPoint &a);//zwracamy obiekt klasy klasy MapDistance zawierajacy odleglosc miedzy dwoma punktami, tym na którym zostały wywołane a punktem a
};