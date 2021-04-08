#pragma once
#include "Operation.h"
class Exponentiation: public Operation {
	private:
		double a;
		double b;

	public:
	 	Exponentiation (double num1,double num2);
		void print()const;
    double eval()const;
};

