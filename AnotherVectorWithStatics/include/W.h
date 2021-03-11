#pragma once
#include <iostream>
#include <math.h>  
#include <utility>

class W {
	public:
  explicit W(int x);
	W(const W& other);
	W(W&& other);
    double &at(int x)const ;
    static double dot(const W& w1,const W& w2);
    double norm()const;
    operator double()const;
    void print(std::string data)const;
    W operator+=(int add);
    W operator+=(const W &w2);
	~W();
	
	private:
		int size;
		double* vals;

};