#include "Persons.h"

void Man::print() const {
	std::cout<<_name<<" ";
	if(_haircut)std::cout<<"nie";
	std::cout<<"obcięty i ";
	if(needShaving)std::cout<<"nie";
	std::cout<<"ogolony";
}

Man::~Man() {
	print();
	std::cout<<" idzie na piwko\n";

}




void Woman::print() const{
	std::cout<<name();
	if(_haircut){
		std::cout<<" nieobcieta";
	}
	else{
		std::cout<<" obcieta";
	}
	std::cout<<" i";
	if(_umalowana){
		std::cout<<" nieumalowana";
		
	}
	else{
		std::cout<<" umalowana";
	}
}
bool Woman::done() const{
	return !_haircut && !_umalowana;
}

void Woman::makeup(){
	_umalowana = false;
	
}

Woman::~Woman() {
	print();
	std::cout<<" idzie na zakupy\n";

}