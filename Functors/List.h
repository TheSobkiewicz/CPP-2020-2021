#pragma once
#include <vector>
#include <iostream>
#include <functional>
class List  {

  public:
  
  List()=default;

  void insert(int n);

  void print(std::string str = "")const;

  int &operator[] (int n);

  List filter(std::function<bool(int)> fun)const;

  private:
  std::vector<int> vec;


};