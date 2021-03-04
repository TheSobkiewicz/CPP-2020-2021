#pragma once 
#include <iostream>
#include "MyLine.h"
//#define MY_ERROR_EXPECTED
class MyPoem{
public:

explicit MyPoem(int x);//konstruktor przypisujacy x do size
void setLine(int x, MyLine data);//funkcja dodajaca linie
void print()const;//funckja wypisujaca
MyPoem(const MyPoem& org);//konstruktor kopiujacy
MyPoem(MyPoem&& org);// konstruktor przenoszacy
~MyPoem();//destruktor
private:
MyLine *poem;
int size;
};