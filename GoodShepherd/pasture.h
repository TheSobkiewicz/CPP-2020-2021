#pragma once
#include <iostream>

class Pasture{
    public:
    Pasture(double v, int sheeps);
    Pasture();
    ~Pasture();
    Pasture operator*(double a);
  friend Pasture operator*(double a, Pasture past);
    Pasture operator*=(double a);
    Pasture operator+(const Pasture &a);
    friend std::ostream& operator<<(std::ostream& os, const Pasture past);
    bool compare(double a,double b);
     bool operator()(Pasture a,Pasture b){ return a.size>b.size;};  

    private:
    double pole;
    bool* tab;
    int size;
};
std::ostream& operator<<(std::ostream& os, const Pasture past);
Pasture operator*(double a, Pasture past);
