#pragma once
#include <iostream>
#include <string>
#include <vector>

class Animal{
	public:
		explicit Animal(std::string name):_name(name){}
		virtual void print() const = 0;
		virtual ~Animal() = default;
		std::string name() const {
			return _name;
		}

	protected:
	std::string _name;

};