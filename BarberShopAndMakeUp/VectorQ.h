#pragma once
#include "Person.h"
#include "Persons.h"
#include <iostream>
#include <string>
#include <vector>
// #include <vector>
#include <memory>
// #include <iostream>
#include <set>
#include <algorithm>
#include <map>

class VectorQ{
	public:
		VectorQ()=default;
		void add(std::unique_ptr<Person> person);
		void print(std::string chain) const;
		void countNames() const;
		std::vector<Woman*> getWomen();
		void haircut(std::string name);
		void haircut();
		void shave(std::string name);
		void shave();
	private:
		std::vector<std::unique_ptr<Person>> vec;
	
};

