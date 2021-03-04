#pragma once
#include "MyNode.h"
#include <iostream>
#include <initializer_list>
class MyList{
public:
  ~MyList();//destruktor
  MyList();//konstruktor domyslny
  MyList(int s);//konstruktor jednoparametrowy
  MyList(std::initializer_list<int> list);//konstruktor z lista
  MyList(const MyList &org);//konstruktor kopiujacy
  MyList( MyList &&org);//konstruktor przenoszacy
  MyList(int (*f)(MyNode*),int size);//funkcja generujaca

  int size()const;//funkcja zwraca size
  bool empty()const;//funkcja sprawdza czy lista jest pusta
  void print()const;//wypisuje liste
  void cleaner(MyNode *toClean);//pomocnicza,czysci liste
  void add(int data);//oddaje node o wartosci add
  void clear();//funkcja czysci liste
private:  
  MyNode *head;
  MyNode *tail;
  int lsize;

};