#pragma once 
#include<iostream>
#include "Element.h"

class StudList//Klasa reprezentująca liste jednokierunkowa
{
  const char *name;//nazwa listy
  Element *head;//Wskaźnik na pierwszy element listy
  Element *tail;// Wskaźnik na ostatni element listy
  public:

  StudList(const char * data);//konstruktor, przypisuje data do name
  ~StudList();//destruktor wypisujacy nazwe listy przy usuwaniu

  Element* getHead();//funkcja zwracajaca wskaznik na pierwszy element listy
  Element* getTail();//funkcja zwracajaca wskaznik na ostatni element listy
  const char *getName()const;//funkcja zwracajaca nazwe listy

  Element *getLast();//funkcja wycinajaca ostatni element listy i zwracajaca go
  void prepend(const char *add);//funkcja dodajaca element z nazwa add na poczatek listy
  void prepend(Element *add);//funkcja dodajaca element add na poczatek listy
  bool isEmpty()const;//funkcja sprawdzajaca czy lista jest pusta
  void print()const;//funkcja wypisujaca liste

   void clearList();//funkcja zwalniajaca liste
   void removeLast();//funkcja usuwajaca ostatni element listy
};