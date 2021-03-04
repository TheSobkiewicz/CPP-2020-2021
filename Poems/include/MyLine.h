#pragma once
#include <iostream>

class MyLine{
public:
  MyLine operator =(const char *data);//operator konwersji z const char
  MyLine(std::string lin);//kontruktor przypisujacy lin do line
  MyLine();//kontruktor domyslny
  MyLine(const char *lin);//konstruktor przypisujacy lin do line
private:
  std::string line;
  friend void convertAndPrint(MyLine a);//funckja wypisujaca
  
};
void convertAndPrint(MyLine a);

