#include "Vector.h"
Vector::Vector(int s){
  size=s;
  tab= new int[s];
  for(int i=0; i<size; i++)tab[i]=0;//Inicja;izujemy wszystkie wartości(unikamy błędów valgrinda)
}
int &Vector::at(int i){
  return tab[i];
}
Vector::Vector(const Vector &org){
  size=org.size;
  tab=new int[size];
  for(int i=0;i<size;i++)at(i)=org.tab[i];
}
void Vector::print(std::string data)const{
  if(size){
  std::cout<<data<<"(";
  for(int i=0;i<size-1;i++)std::cout<<tab[i]<<", ";
  std::cout<<tab[size-1]<<")\n";
  }
}
double Vector::dot(const Vector &a,const  Vector &b){
  double result=0;
  for(int i=0;i<a.size;i++)result+=a.tab[i]*b.tab[i];
  return result;
}
double Vector::norm()const{
  double result =0;
  for(int i=0;i<size;i++)result+=tab[i]*tab[i];
  return sqrt(result);
}
Vector::operator double()const{
  return norm();
}
Vector Vector::sum(const Vector &a, const Vector &b)
{
  Vector result(a.size);
  for(int i=0;i<result.size;i++)result.at(i)=a.tab[i]+b.tab[i];
  return result;
}
Vector Vector::sum(const Vector &a,int b)
{
  Vector result(a.size);
  for(int i=0;i<result.size;i++)result.at(i)=a.tab[i]+b;
  return result;
}
Vector::~Vector(){
  size=0;
  delete [] tab;
}
 
 Vector::Vector( Vector &&org){
  size=org.size;
  tab=new int[size];
  for(int i=0;i<size;i++)at(i)=org.tab[i];
  org.size=0;
 }

