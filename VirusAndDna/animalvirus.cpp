#include "animalvirus.h"

AnimalVirus::AnimalVirus(string virus, string animal, std::vector< Nukleotyp > seq):Virus(virus){
	animalName = animal;
  	set_RNA(seq);
}


string AnimalVirus::get_animal_host(){
	return animalName;
}

AnimalVirus::AnimalVirus(AnimalVirus&& other): Virus(other){
  
	animalName=(std::exchange(other.animalName,""));
}

AnimalVirus::AnimalVirus(AnimalVirus& other):Virus(other){
	animalName= other.animalName;
}

AnimalVirus& AnimalVirus::operator=(AnimalVirus &&dummy){
	AnimalVirus *add= new AnimalVirus(std::move(dummy));
  add->rna=&add->rna->mutate();
  return *add;
} 