#include "ComplexNumber.h"
ComplexNumber::ComplexNumber(double a , double b){
  real=a;
  im=b;
}

ComplexNumber::operator double()const{
	return real;
}
std::ostream& operator <<(std::ostream& os,const ComplexNumber &dummy){
	os << dummy.real << " + " << dummy.im <<"i";
	 
	return os;
}
ComplexNumber ComplexNumber::operator+(ComplexNumber a)const{
  return ComplexNumber(real+a.real,im+a.im);
}
ComplexNumber operator+(int x ,ComplexNumber a){
  return ComplexNumber(x+a.real,a.im);
}
ComplexNumber ComplexNumber::operator*(ComplexNumber a)const{

  return ComplexNumber(real*a.real - im*a.im , real*a.im + im*a.real);
}
double& ComplexNumber::operator[](int x){
  if(x==0)return real;
  else return im;
}
ComplexNumber ComplexNumber::operator*=(int a){
	real=real*a;
	im=im*a;
	return *this;
}
ComplexNumber ComplexNumber::operator ++(int){
	
	ComplexNumber temp; 
    temp.real = real++;
	temp.im = im; 
    return temp; 
}
ComplexNumber ComplexNumber::operator ++(){
	
	ComplexNumber temp; 
    temp.real = ++real;
	temp.im = im; 
    return temp; 
}
bool ComplexNumber::operator>(ComplexNumber a)const{
  return real*real+im*im > a.real*a.real +a.im*a.im;
}

ComplexNumber ComplexNumber::operator-(ComplexNumber a)const{
  return ComplexNumber(real-a.real,im-a.im);
}