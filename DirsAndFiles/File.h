#pragma once
#include <string.h>
#include <iostream>
using namespace std;

// class Object {
//   
//   protected:
//   string name;
// }

class File{
  public:
  File(string n): name(n) {}
  virtual ostream &print(ostream & out)const;
  void space(int n){
    spaces=n+2;
    }
  virtual void add( File * f) {};

  string getName()const {return name;}
  virtual File *get(string n);
  virtual ~File(){}
  friend ostream & operator << (ostream &o, const File & f) ;
  protected:

  int spaces = 0;
  string name;
  
};
