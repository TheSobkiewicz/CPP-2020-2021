#pragma once
class Lozko: public virtual Mebel {
  public:

Lozko(int x, int y, int z, int s):Mebel(x,y,z),spanie(s){}

virtual ostream& print( ostream & stream) const {

  stream<<"Lozko: ";
	Mebel::print(stream);
	stream <<" sz. spania: "<<spanie;

	return stream;
}

virtual ~Lozko() {

	cout << "~Lozko" << endl;

}

protected:
int spanie;

};