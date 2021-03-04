/* Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał
   a wynik jego działania był taki sam, jak podany na końcu tego pliku.

 * Zdefiniuj klasę Fraction reprezentujacą ułamek zwykły.
   posiadającą dwa pola prywatne _l i_m typu int.

 * Zdefiniuj niezbędne konstruktory i metody pomocnicze (w ramach oszczędności
 czasu, zaimplementuj je w pliku nagłówkowym) Ułamek jest upraszczany na etapie
 konstruktora (zdefiniuj funkcję simplify) oraz po każdej operacji dodawania lub
 mnozenia. W ramach uproszczenia, w komentarzu umieszczono kod funkcji nwd,
   służacej do wyliczenia największego wspólnego dzielnika.

 * Zaimplementuj operatory dodawania +, mnożenia *
   (również w wersji liczba * ułamek), operator +=
   operator przypisania =, operator logiczny >, operator liczby przeciwnej -,
 ostream << oraz konwersję do double i operator[] służący do wypisania
 odpowiednio licznika i mianownika. Operatory, które mogą być metodami klasy,
 zaimplementuj w klasie, pozostałe jako funkcje zewnętrzne.

*/

#include "fraction.h"
#include <iostream>

using namespace std;

/* do wykorzystania w funkcji simplify
int nwd(int m, int n){
	int oldm, oldn;
	while( m % n != 0 ){
		oldm = m;
		oldn = n;
		m = oldn;
		n = oldm % oldn;
	}
	return n;
} */

int main() {
	Fraction f1(6, 8);
	const Fraction f2(3, 2);
	Fraction f3(6, 2);
	Fraction f3b(3);
	cout << "Ulamki po skroceniu w konstruktorze:" << endl;
	cout << "f1 = " << f1 << endl;
	cout << "f2 = " << f2 << endl;
	cout << "f3 = " << f3 << endl;
	cout << "f3b = " << f3b << endl;
	cout << Fraction(2, -3) << endl; // kwestię znaku załatw w funkcji simplify

	double val = f1;
	cout << "Ulamek dziesietny f1: " << val << endl;
	cout
		<< ((f1 > f2) ? "f1 jest wiekszy od f2\n" : "f1 jest mniejszy od f2\n");
	cout
		<< ((f3 > f2) ? "f3 jest wiekszy od f2\n" : "f3 jest mniejszy od f2\n");

	cout << "**********  Prosta arytmetyka *************" << endl;
	Fraction f4 = f1 * f2;
	f3 = f1 * f4;
	cout << "Iloczyn: " << f1 << " * " << f2 << " = " << f4 << endl;
	cout << "Iloczyn: " << f1 << " * " << f4 << " = " << f3 << endl;

	cout << "Iloczyn: "
		 << "2 * " << f1 << " = " << 2 * f1 << endl;
	cout << "Iloczyn: "
		 << "32 * " << f1 << "* " << f4 << " = " << 32 * f1 * f4 << endl;
	cout << "Suma: " << f1 << " + " << f2 << " = " << f1 + f2 << endl;
	f3 = f1 + f4;
	f3 += -3;
	cout << "Suma: " << f1 + f4 << " + (-3) = " << f3 << endl;
	cout << "Suma: " << f1 + f4 << " + (-3) = " << static_cast<float>(f3)
	 	 << endl;
	cout << f1 << " + " << f2 << " * " << f3 << " = " << f1 + f2 * f3 << endl;

	cout << "**********  Eksperymenty *************" << endl;
	cout << "Licznik: " << f3[0] << endl;   // indeks=0 licznik
	cout << "Mianownik: " << f3[1] << endl; // indeks>0 mianownik
	f3 = -f1;
	cout << "f3 = -f1   " << f3 << endl;
	cout << "f1 =  " << f1 << endl;
	Fraction f5 = std::move(f3);
	cout << f5 << " + " << f3 << " = " << f5 + f3 << endl;
	cout << "Licznik: " << f3[0] << endl;
	cout << "Mianownik: " << f3[1] << endl;

	return 0;
}

/* Oczekiwany wynik: ./main
Ulamki po skroceniu w konstruktorze:
f1 = 3/4
f2 = 3/2
f3 = 3
f3b = 3
-2/3
Ulamek dziesietny f1: 0.75
f1 jest mniejszy od f2
f3 jest wiekszy od f2
**********  Prosta arytmetyka *************
Iloczyn: 3/4 * 3/2 = 9/8
Iloczyn: 3/4 * 9/8 = 27/32
Iloczyn: 2 * 3/4 = 3/2
Iloczyn: 32 * 3/4* 9/8 = 27
Suma: 3/4 + 3/2 = 9/4
Suma: 15/8 + (-3) = -9/8
Suma: 15/8 + (-3) = -1.125
3/4 + 3/2 * -9/8 = -15/16
**********  Eksperymenty *************
Licznik: -9
Mianownik: 8
f3 = -f1   -3/4
f1 =  3/4
-3/4 + 0 = -3/4
Licznik: 0
Mianownik: 1
*/
