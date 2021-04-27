#pragma once
#include "Mebel.h"

class Sofa: public virtual Mebel{
  public:
Sofa( int x, int y, int z, int s):Mebel(x,y,z),siedzisko(s){}

virtual ostream& print( ostream & stream) const {
  stream<<"Sofa: ";
	Mebel::print(stream);
	stream << " siedzisko: "<<siedzisko;
return stream;
}
virtual ~Sofa() {
  cout<<"~Sofa\n";
}

protected:
int siedzisko;




};