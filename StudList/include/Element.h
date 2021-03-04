#pragma once 
#include <iostream>
class Element
{
  const char *name;
  Element *next=nullptr;
  friend class studList;//Zaprzyjazniamy z klasa studList *dodane po napisaniu całego programu getterami i setterami :(*
  public:
  Element(const char *data);//konstruktor nadajacy name wartosc data i next na nullptr
  Element();//konstruktor domyslny ustawiajacy null i next na nullptr
  ~Element();//destruktor wypisujacy name przy zwalnianiu elementu

  Element *getnext();//funkcja zwracajaca nastepny element listy
  void setnext(Element *data);//funkcja ustawiajaca nastepny element na data

  const char *getName();//funkcja zwracajaca name
  void printName();//funkcja wypisujaca name
};