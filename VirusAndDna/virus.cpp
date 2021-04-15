#include "virus.h"


string Virus::get_name() {
  return name;
}

int Virus::get_age() {
  return age;
}

Virus::~Virus(){
delete rna;
}

Virus::Virus(string n):name(n),rna(nullptr){}


RNA* Virus::get_RNA(){
	return rna;
}



void Virus::set_RNA(const std::vector< Nukleotyp > seq_){
		rna=new RNA(seq_);
}


Virus::Virus( Virus& other){
	name = other.name;
  set_RNA(other.rna->get_RNA());
	age = 0;
  other.age+=1;
}

Virus::Virus(Virus&& other): name(std::exchange(other.name,"")),age(std::exchange(other.age,0)),rna(std::exchange(other.rna,nullptr)){
  rna=&rna->mutate();
  }

