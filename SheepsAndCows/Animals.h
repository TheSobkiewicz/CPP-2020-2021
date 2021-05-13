#pragma once
#include "Animal.h"
class Sheep: public Animal{
	public:
		Sheep(std::string name):Animal(name){}
		
		void print() const;
		void shear();
	private:
	bool isSheared = false;
};


class Horse: public Animal {
	public:
		Horse(std::string name):Animal(name){}
		void print() const;
	
	private:



};


class Cow: public Animal {
	public:
		Cow(std::string name):Animal(name){}
		void print() const;
};