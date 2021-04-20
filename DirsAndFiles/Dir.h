#pragma once 
#include "File.h"
#include <vector>
using namespace std;
class  Dir final : public File {
   
  public:

  Dir(string n):File(n){}

  File *get(string n);
  void operator += (File * f);
  void add ( File * f);
  Dir * findDir(string n) const;
  ostream &print(ostream & out)const;

  ~Dir();

  private:
    vector<File *> vec;

};
