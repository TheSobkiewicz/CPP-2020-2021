#pragma once

#include <iostream>
#include <math.h>
#include <utility>

class ComplexNumber{
	
  public:
friend ComplexNumber operator +(int x,ComplexNumber a);
explicit ComplexNumber(double a=0 ,double b=0);
explicit operator double()const;
ComplexNumber operator +(ComplexNumber a)const;
ComplexNumber operator *(ComplexNumber a)const;
ComplexNumber operator*=(int a);
friend std::ostream& operator <<(std::ostream& os, const ComplexNumber &dummy);
bool operator >(ComplexNumber)const;
ComplexNumber operator ++(int);
ComplexNumber operator ++();
ComplexNumber operator-(ComplexNumber a)const;

  double& operator [](int x);

	private:
	double real;
	double im;
};
std::ostream& operator <<(std::ostream& os,const ComplexNumber &dummy);

ComplexNumber operator +(int x,ComplexNumber a);