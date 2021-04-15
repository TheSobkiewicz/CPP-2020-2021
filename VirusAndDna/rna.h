#pragma once

// *** Nie wolno modyfikować tego pliku ***

#include <vector>
#include <ostream>


//-------------------------------------------------------------
// Implementacja nukleotydów
enum Nukleotyp { 
	A='A', // adeine 
	G='G', // guanine
	C='C', // citozine
	T='T', // thymine
	U='U'  // uracil
};


//-------------------------------------------------------------
// Implementacja sekwencji nukleotydów danych typem Nukleotyp
class RNA {

	// operator drukujący sekwencję genów na wyjście ostream.
	friend std::ostream& operator<<(std::ostream& out, const RNA & seq_);

 public:	

	// zwraca sekwencję genów (nukleotydów) w postaci wektora
	std::vector< Nukleotyp > get_RNA() const { return chain; }

	RNA( const std::vector< Nukleotyp > seq_ ): chain(seq_) { }
	
	//mutuje łańcuch RNA poprzez cykliczne przesunięcie w lewo
	RNA & mutate ();

 protected:

	// ciąg nukleotydów zaimplementowany jako wektor	
	std::vector< Nukleotyp > chain;

};