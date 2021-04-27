#pragma once
#include "Sofa.h"
#include "Lozko.h"

using namespace std;

class Kanapa: public Sofa, public Lozko  {

public:

	Kanapa(int x, int y, int z, int s, int sp):Mebel(x,y,z),Sofa(x,y,z,s),Lozko(x,y,z,sp){}

	virtual ostream& print( ostream & stream) const {

		
  stream<<"Jako ";
  Mebel::print(stream);
  stream <<"\nJako: ";
  Sofa::print(stream);
  stream << "\nJako ";
  Lozko::print(stream);

	return stream;
	}

	virtual ~Kanapa() {

		cout << "~Kanapa" << endl;

	}


};