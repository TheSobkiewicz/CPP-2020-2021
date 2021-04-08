#pragma once
#include "Operation.h"
class Division: public Operation {
	private:
		double a;
		double b;

	public:
		Division (double num1,double num2);
		void print()const;
    	double eval()const;
};

