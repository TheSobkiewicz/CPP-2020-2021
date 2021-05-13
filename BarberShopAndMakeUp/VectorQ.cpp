#include "VectorQ.h"
#include "Persons.h"
void VectorQ::add(std::unique_ptr<Person> person){
	vec.push_back(std::move(person));
}

void VectorQ::print(std::string chain) const{
	std::cout<<" "<<chain<<" \n";
	for(auto &animal: vec){
		animal->print();
		std::cout<<"\n";
	}
	std::cout<<"\n";
}



void VectorQ::countNames() const {
	std::map<std::string, int> temp;
	for(auto &a : vec) {
		temp[a->name()]++;
	}

	for(auto name: temp) {
		std::cout<<name.first<<": "<<name.second<<std::endl;
	}	
}

std::vector<Woman*> VectorQ::getWomen(){
	std::vector<Woman*> herd;
	for(auto &animal: vec){
		auto dummy = dynamic_cast<Woman*>(animal.get());
		if (dummy) {
		herd.push_back(dummy);
		}


	}
	return herd;
}


void VectorQ::haircut(std::string name){
	for (auto &person : vec){
		
		if(person->name()==name){
			person->haircut();
			if(person->done()) {
				auto id = find(vec.begin(),vec.end(),person);
				vec.erase(id);
			}
			break;
		}
	}

}
void VectorQ::haircut(){

	for (auto &person: vec){
		person->haircut();

		if(person->done()){
			auto id = find(vec.begin(),vec.end(),person);
			vec.erase(id);
			
		}
		break;
	}

}

void VectorQ::shave(std::string name){
	for (auto &person : vec){
		if(person->name()==name){

			person->shave();
			if(person->done()) {
				auto id = find(vec.begin(),vec.end(),person);
				vec.erase(id);
			}
			break;
		
		}
	}
}
void VectorQ::shave(){
	for (auto &person : vec){
			person->shave();
			if(person->done()) {
				auto id = find(vec.begin(),vec.end(),person);
				vec.erase(id);
			}
			break;
		}
	}