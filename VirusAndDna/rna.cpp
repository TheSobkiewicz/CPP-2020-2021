#include "rna.h"
#include<iostream>
RNA& RNA::mutate() { 
	chain.push_back(chain[0]);
    chain.erase(chain.begin());
//   std::cout<<"MUTUJE: "<<*this;
  	return *this;
}



std::ostream& operator<<(std::ostream& out, const RNA & seq_){
	for (char i:seq_.chain){
		out << " " << i;
	}
	out << "\n";
	return out;

}