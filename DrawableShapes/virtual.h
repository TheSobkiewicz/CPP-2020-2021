#pragma once 
#include "ostream"
#include <string>
#include <sstream>
#include <cmath>

class ClosedShape {
  public:
  virtual double area() const = 0;

};

class Transformable {
  public:
  virtual void shift(double x1, double y1) = 0;
};


class Drawable {

  public:
  virtual void print() const = 0;
  virtual double length() const = 0;

};


