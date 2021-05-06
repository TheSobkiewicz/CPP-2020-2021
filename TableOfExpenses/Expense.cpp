#include "Expense.h"
#include <iomanip>


void Expense::print()const{
	std::cout<<_day<<" :";
	std::for_each(vec.begin(),vec.end(),[](float dummy){
		std::cout<<std::setw(6)<<dummy;
	});
	std::cout<<"\n";

}

float Expense::mean() const {
	float sum=0;
	for(auto a:vec) {
		sum+=a;
	}
	return sum/vec.size();
}

int Expense::getSize() const {
	return vec.size();
}


