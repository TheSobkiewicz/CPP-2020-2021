#include "Exponentiation.h"
// #include "Operation.h"
#include <math.h>
Exponentiation::Exponentiation (double num1,double num2): a(num1),b(num2){

}

void Exponentiation::print()const{
	std::cout<<a<<" ^ "<<b;
}
double Exponentiation::eval() const{
  return pow(a,b);
}