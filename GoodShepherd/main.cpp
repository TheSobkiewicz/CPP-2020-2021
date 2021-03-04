
/* Celem ćwiczenia jest przećwiczenie różnych operatorów, w tym () oraz <<
Należy zdefiniować klasę Pasture, obrazującą pastwisko, które jest kwadratem o zadanym boku. Na pastwisku pasie się zadana liczba owiec, białych lub czarnych.
Owieczka biała jest oznaczana liczbą 0, zaś czarna liczbą 1.

Klasa MUSI mieć przynajmniej następujące pola:
	* pole powierzchni pastwiska (typ double)
	* dynamiczna tablica owieczek (typ bool* )
Klasa musi mieć (jako minimum) następujące konstruktory:
	* konstruktor tworzący pastwisko o zadanym boku i liczbie owiec;
	   Kolor owcy (czarny, biały) jest losowany funkcją rand()
	* Konstruktor domyślny, który co najwyżej zeruje pola
	* Konstruktor kopiujący i przenoszący.

Należy przeładować następujące operatory:
	* przypisania kopiującego i przenoszącego
	* operator + dla dodawania dwóch pastwisk
	  Dodanie dwóch pastwisk dodaje ich powierzchnie i owce.
    Zakładamy, że przy dodawaniu pastwiska zachowujemy uporządkowanie owiec.
	* operator =* dla mnożenia pastwiska przez liczbę double x
	   W wyniku powiększamy pole powierzchni x razy.
	* operator * dla mnożenia pastwiska przez double z lewej bądź prawej strony.
	   Efekt taki sam jak dla =*.
	* Operator ()
	   Należy utworzyć predykat, który porównuje powierzchnie dwóch pastwisk.
	* Operator << drukujący obiekt Pasture do stdout
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include "pasture.h"

using namespace std;


int main() {

	srand(122332);// seed dla generatora liczb pseudolosowych
	// Tworzymy 3 pastwiska o bokach danych jako pierwszy argument i liczbie owiec danej drugim argumentem.
	cout << "***  ETAP 1 ***\n" << endl;	
	  
    Pasture ps1(3.0,5), ps2(4,8), ps3 (1,2);
	  cout << ps1 <<  ps2 << endl;

	cout << "***  ETAP 2 ***\n" << endl;

	// // Testujemy operatory = , + , *= , *
	  Pasture sum1 = ps1+ps2, sum2 = Pasture(sqrt(2),3)+Pasture(sqrt(5),4);
	  cout << sum1 << sum2;
	  cout << (sum1*=2.) << 3.*sum2 << sum2*3. << endl;

	cout << "***  ETAP 3 ***\n" << endl;

	// Tworzymy STL wektor pastwisk i sortujemy malejąco używając predykatu, danego jako obiekt klasy Pasture.
  	vector<Pasture> fields;
	  fields.push_back(ps1);
	  fields.push_back(ps2);
	  fields.push_back(ps3);
	  fields.push_back(sum1);
	  fields.push_back(sum2);

	  Pasture pred; 
	  sort(fields.begin(),fields.end(), pred);

	  vector<Pasture>::iterator it = fields.begin();
	  while (it!=fields.end()) { 
	  	cout << *it;
		it++;
	  } 

return 0;
}

/* Oczekiwany wynik
./main
***  ETAP 1 ***

Pole: 9, owce: 0 1 0 1 1 
Pole: 16, owce: 0 0 1 1 0 1 1 1 

***  ETAP 2 ***

Pole: 25, owce: 0 1 0 1 1 0 0 1 1 0 1 1 1 
Pole: 7, owce: 0 1 1 0 0 1 0 
Pole: 50, owce: 0 1 0 1 1 0 0 1 1 0 1 1 1 
Pole: 21, owce: 0 1 1 0 0 1 0 
Pole: 21, owce: 0 1 1 0 0 1 0 

***  ETAP 3 ***

Pole: 50, owce: 0 1 0 1 1 0 0 1 1 0 1 1 1 
Pole: 16, owce: 0 0 1 1 0 1 1 1 
Pole: 9, owce: 0 1 0 1 1 
Pole: 7, owce: 0 1 1 0 0 1 0 
Pole: 1, owce: 0 0 
*/