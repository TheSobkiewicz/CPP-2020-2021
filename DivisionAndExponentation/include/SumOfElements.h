#pragma once
#include "Operation.h"
class SumOfElements: public Operation{
	private:
		double  *table;
		int number;
	public:
		SumOfElements(double *tab,int num);
		void print()const;
    double eval()const;
};

