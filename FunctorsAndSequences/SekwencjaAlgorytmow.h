#pragma once
#include <iostream>
#include <functional>
#include "Argumenty.h"

class SekwencjaAlgorytmow {
  public: 
  void add (std::function< Argumenty(const Argumenty&)> fun);//funckja dodajaca funkcje add do vektora funkcji vec
  Argumenty procesuj (const Argumenty &a)const;//funkcja przeprowadzajaca operacje z vektora vec na obiekcie a klasy Argumenty

  private:
  std::vector<std::function<Argumenty(const Argumenty&)>> vec;
};