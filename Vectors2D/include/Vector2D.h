#pragma once
#include <iostream>
#include <cmath>
class Vector2D//klasa reprezentujaca wektor
{
  public:
    static int count;//licznik utworzonych wektorów
	  static Vector2D fromCarthesian(double x, double y);//named constructor idiom zwracajacy obiekt o wartości x = x oraz y = y (wywołuje konstruktor domyślny więc nazwy sie nie nakładają) 
    static Vector2D fromPolar(double r, double phi);//named constructor idiom wyliczający współrzedne na podstawie promienia r oraz kąta phi i wywolujacy konstruktor domyślny dla tych wartości
    void print(std::string name="")const;//funkcja wypisujaca wektor w formacie (name(x,y))
    double dot(const Vector2D &b)const;//funkcja zwracajaca iloczyn skalarny wektora na ktorym zostala wywolana oraz wektora b
    Vector2D add(const Vector2D &b)const;//funkcja zwracajaca wektor bedacy suma wektora na ktorym zostala wywolana oraz wektora b
    Vector2D(const Vector2D &orginal);//konstruktor kopiujacy
    Vector2D(const Vector2D &&orginal);//konstruktor przenoszacy
    ~Vector2D();//destruktor
  private:
    Vector2D(double x1=0, double y1=0);//konstruktor domyślny, wywolywany przez inne konstruktory, przypisuje wartosc x1 do x i y1 do y
     double x;
     double y;
};