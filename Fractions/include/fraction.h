#pragma once
#include <iostream>
int nwd(int m, int n);
void simplify(int &l, int &m);
class Fraction{
    friend std::ostream& operator<<(std::ostream& strm, const Fraction &K);
    public:
    Fraction(int l, int m=1){
        simplify(l,m);
         _l=l;
         _m=m;
     }

    operator double(){
        return (double)_l/_m;
    }

  bool operator >(Fraction dummy);

  Fraction operator+(const Fraction &a);

  friend Fraction operator*(int i,const Fraction &a);

  Fraction operator*(const Fraction &a)const;

  void operator+=(const int a);

  int operator[](int i);

  Fraction(const Fraction &other);

  Fraction(Fraction &&other);

  Fraction &operator=(const Fraction dummy);

  Fraction operator-();
  
private:
  int _l,_m;
};

 std::ostream& operator<<(std::ostream& strm, const Fraction &K);