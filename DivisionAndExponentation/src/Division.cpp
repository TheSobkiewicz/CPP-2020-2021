#include "Division.h"
// #include "Operation.h"

Division::Division(double num1,double num2):a(num1),b(num2){

}

void Division::print()const{
	std::cout<<a<<" / "<<b;
}
double Division::eval()const {
  return a/b;
}