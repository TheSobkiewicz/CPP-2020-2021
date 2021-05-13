#include "Animals.h"

//- Owca Beata nieostrzyzona
void Sheep::print() const {
	std::cout<<"- Owca "<<_name;
	if(isSheared){
		std::cout<<" ostrzyzona";
	}
	else{
		std::cout<<" nieostrzyzona";
	}

}

void Horse::print() const {
std::cout<<"- Kon "<<_name;
}

void Cow::print() const {
	std::cout<<"- Krowa "<<_name;
}


void Sheep::shear() {
	isSheared = true;
}