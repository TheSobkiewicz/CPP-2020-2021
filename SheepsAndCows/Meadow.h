#pragma once
#include "Animal.h"
#include "Animals.h"
#include <iostream>
#include <string>
#include <vector>
// #include <vector>
#include <memory>
// #include <iostream>
#include <set>
#include <algorithm>
#include <map>


class Meadow{
	public:
		Meadow()=default;
		void add(std::unique_ptr<Animal> animal);
		void print(std::string chain) const;
		void countNames() const;
		std::vector<Sheep*> getSheepHerd();
	private:
		std::vector<std::unique_ptr<Animal>> vec;
	
};

