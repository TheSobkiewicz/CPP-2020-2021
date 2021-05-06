#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

class Expense {
	public:
		Expense(std::string day,std::vector<float> init):_day(day),vec(init){};
		void print() const;
		float mean() const;
		int getSize() const;
		float getValueAt(int i) const{
			return vec[i];
		}

		float get(int a);

	private:
		std::vector<float> vec;
		std::string _day;
};
