#include "Vector2D.h"

int Vector2D::count;
  Vector2D::Vector2D(double x1, double y1):x(x1),y(y1){
count++;
}

Vector2D Vector2D::fromCarthesian(double x, double y){
  return Vector2D(x,y);
}
Vector2D Vector2D::fromPolar(double r, double phi){
  return Vector2D(r*cos(phi*M_PI/180),r*sin(phi*M_PI/180));
}

void Vector2D::print(std::string name)const{
  std::cout<<name<<"("<<x<<","<<y<<")\n";
}

double Vector2D::dot(const Vector2D &b)const{
  return (x*b.x+y*b.y);
}

Vector2D Vector2D::add(const Vector2D &b)const{
  return Vector2D(x+b.x,y+b.y);
}

Vector2D::Vector2D(const Vector2D &orginal):x(orginal.x), y(orginal.y){
  count++;
std::cout<<"copying ";
orginal.print();
}

Vector2D::Vector2D(const Vector2D &&orginal):x(orginal.x), y(orginal.y){
std::cout<<"moving";
orginal.print();
count++;
}

Vector2D::~Vector2D()
{
  count--;
}
