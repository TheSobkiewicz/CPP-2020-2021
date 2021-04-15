#pragma once
#include "rna.h"
#include <iostream>
#include <utility>
using namespace std;
class Virus {
  public:
	
	string get_name();
  	int get_age();
    Virus(string n);
	RNA* get_RNA();
	~Virus();

	Virus(Virus&& other);
	void set_RNA(const std::vector< Nukleotyp > seq_);

	Virus( Virus& other);
	Virus()=default;

	  
  	string name;
  	RNA* rna;
  	int age=0;


};