#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <functional>

#include "Expense.h"

class Table{
	public:
		Table() = default;

		void operator+=(const Expense &day);

		void print()const;

		Table& sort(int kol);

		Table& sortByMean();

	private:
		std::vector<Expense> vec;
		int size = 0;
};