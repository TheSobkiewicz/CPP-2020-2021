#pragma once

#include <iostream>

using namespace std;

class Mebel {

	public: 
	
		Mebel(int w, int h, int l ): _width(w), _height(h), _lenght(l) {}

		virtual ostream & print(ostream & out) const {

			out<<"Mebel " << "sz:" << _width << " wys:" << _height << " dl:" << _lenght;

			return out;

		}

		virtual ~Mebel() {

				cout << "~Mebel" << endl;

		}


	protected:

		int _width;

		int _height;

		int _lenght;

};

ostream & operator << (ostream & out, const Mebel & m) {

	return m.print(out);

}