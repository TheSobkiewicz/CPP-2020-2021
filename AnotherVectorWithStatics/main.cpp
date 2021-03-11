#include <iostream>
#include "include/W.h"

// #define COMPILATION_ERROR

int main() {
	W w1(3);		
	const W w2(2);	

	w1.at(0) = 1;
	w1.at(1) = 2;
	const W w3 = w1;
	w1.at(1) = 0;
	w3.at(2) = 4;

	w1.print("w1: ");
	w2.print("w2: ");
	w3.print("w3: ");

	double prod = W::dot(w1, w3); 
	std::cout << "Dot product = " << prod << std::endl;
	std::cout << "Another dot product: " << std::endl;
	W::dot(w1,w2);

	double norm = static_cast<double>(w3); // == w3.norm();
	std::cout << "Norm = " << norm << ", " << w3.norm() << std::endl;
	
	W w4{w1};
	w4+=w3; 
	w4.print("w4 = w1 + w3: ");

	W w5 = std::move(w4);
	w5.print("w5: ");

	(w1+=1).print("w1 + 1 : ");
	
	#ifdef COMPILATION_ERROR
	W strange = 5;
	#endif
}
/*
//Output:
w1: [1, 0, 0]
w2: [0, 0]
w3: [1, 2, 4]
Dot product = 1
Another dot product: 
Error, vectors of different dimensions!
Norm = 4.58258, 4.58258
w4 = w1 + w3: [2, 2, 4]
w5: [2, 2, 4]
w1 + 1 : [2, 1, 1]
*/
