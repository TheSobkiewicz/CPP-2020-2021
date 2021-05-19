#pragma once
#include <iostream>
class X { //prosta klasa przechowywująca tekst
  public:
  std::string& get()  { //funckja zwracajaca referencje do tekstu
    return val;
  }
  X(std::string a):val(a){} //konstruktor przyjmujacy tekst
  X() = default;
  virtual ~X() {//destruktor wypisujacy tekst w usuwanym obiekcie
    std::cout<<"deleting X "<<val<<std::endl;
  }
  protected:
  std::string val = "";
};

class Y: public X {//prosta klasa przechowywująca tekst, jest prawie identyczna z klasa X
  public:
 Y(std::string a):X(a){}
  ~Y() {//destruktor wypisujacy niszczony obiekt
    std::cout<<"deleting Y "<<val<<std::endl;
  }

};