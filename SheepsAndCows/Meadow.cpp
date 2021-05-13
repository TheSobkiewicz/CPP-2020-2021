#include "Meadow.h"


void Meadow::add(std::unique_ptr<Animal> animal){
	vec.push_back(std::move(animal));
}



//=== Zwierzeta na lace ===
void Meadow::print(std::string chain) const{
	std::cout<<"=== "<<chain<<" ===\n";
	for(auto &animal: vec){
		animal->print();
		std::cout<<"\n";
	}

}



void Meadow::countNames() const {
	std::map<std::string, int> temp;
	for(auto &a : vec) {
		temp[a->name()]++;
	}

	for(auto name: temp) {
		std::cout<<name.first<<": "<<name.second<<std::endl;
	}	
}

std::vector<Sheep*> Meadow::getSheepHerd(){
	std::vector<Sheep*> herd;
	for(auto &animal: vec){
		auto dummy = dynamic_cast<Sheep*>(animal.get());
		if (dummy) {
		herd.push_back(dummy);
		}


	}
	return herd;
}