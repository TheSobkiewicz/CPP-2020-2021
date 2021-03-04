#include "Vector2D.h"
int Vector2D::count;
Vector2D Vector2D::fromCarthesian(std::string data , double a, double b)
{
return Vector2D(data,a,b);
}

Vector2D Vector2D::fromCarthesian( double a, double b)
{
return Vector2D("Vx",a,b);
}

Vector2D Vector2D::fromPolar(std::string data, double r, double rad)
{
return Vector2D(data,r*cos(rad*M_PI/180),r*sin(rad*M_PI/180));
}

Vector2D::Vector2D(std::string data,double a, double b)
{
  name=data;
  x=a;
  y=b;
  count++;
}

Vector2D::~Vector2D()
{
  count--;
}

Vector2D::Vector2D(const Vector2D &other)
{
  std::cout<<"--- kopiowanie: ";
other.print(other.name);
name=other.name;
x=other.x;
y=other.y;
count++;
}

void Vector2D::print(std::string data)const
{
  std::cout<<data<<"("<<x<<","<<y<<")"<<std::endl;
}

double Vector2D::dot(const Vector2D &v2)const
{
  return x*v2.x+y*v2.y;
}

Vector2D Vector2D::add(const Vector2D &v2)const
{
return fromCarthesian("Vx",x+v2.x,y+v2.y);
}

Vector2D::Vector2D(Vector2D &&other):name(other.name),x(other.x),y(other.y)
{
std::cout<<"--- przenoszenie: ";
other.print(other.name);
name=other.name;
other.x=0;
other.y=0;
count++;
}
