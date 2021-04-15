#pragma once
#include "rna.h"


class DNA : public RNA{
		friend std::ostream& operator<<(std::ostream& out, const DNA & dummy);
  public:

  DNA(RNA &a, RNA &b):RNA(a.get_RNA()), chain1(b.get_RNA()){}

	private:
  std::vector< Nukleotyp > chain1;
};

std::ostream& operator<<(std::ostream& out, const DNA & dummy){

		// out<<dummy.rna1;
	for (char i:dummy.chain){
		out<<i<<" ";
	}
	out<<"\n";
	for (unsigned int i= 0; i<dummy.chain.size();i++){
		out<<"| ";
	}
	out<<"\n";
	for (char i:dummy.chain1){
		out<<i<<" ";
	}
	out<<"\n";

	return out;
}