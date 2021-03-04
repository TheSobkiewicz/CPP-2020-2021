#pragma once
#include <iostream>
#include <math.h>
class Vector2D
{
  std::string name;
  double x;
  double y;

public:
static int count;

Vector2D(std::string data="Vx",double a=0,double b=0);
static Vector2D fromPolar(std::string data="Vx", double r=0, double rad=0);
static Vector2D fromCarthesian(std::string data="Vx", double a=0, double b=0);
static Vector2D fromCarthesian(double a=0, double b=0);
~Vector2D();
Vector2D(const Vector2D &other);
Vector2D( Vector2D &&other);

void print(std::string data)const;
double dot(const Vector2D &v2)const;
Vector2D add(const Vector2D &v2)const;
};
