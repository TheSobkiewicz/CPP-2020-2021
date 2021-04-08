#include "SumOfElements.h"



SumOfElements::SumOfElements(double* tab,int num):table(tab),number(num){

}

void SumOfElements::print()const{
	for(int i = 0; i<number-1;i++){
		std::cout<<table[i]<<" + ";
	}
	std::cout<<table[number-1];
	
}

double  SumOfElements::eval()const{
  double sum =0;
	for(int i = 0; i<number;i++){
		sum +=table[i];
		}
	return sum;
}
