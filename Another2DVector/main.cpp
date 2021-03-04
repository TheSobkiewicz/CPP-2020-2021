/* Celem zadania jest przećwiczenie konstruktorów, a także funkcji i zmiennych statycznych.

Wektor można przedstawić np. we współrzędnych biegunowych lub kartezjańskich lecz konstruktor z dwoma argumentami double byłby niejednoznaczny:
   Vector2D (double x, double y);
   Vector2D (double r, double phi); // błąd - zdublowany z poprzednim
Należy użyć tzw. named constructor idiom, tj. stworzyć funkcje zwracające obiekt.
  - fromCarthesian (std::string name, double x, double y);
  - fromPolar (std::string name, double r, double phi);
Jeśli w konstruktorach nazwa nie zostanie podana, przyjmuje wartość Vx.
Konstruktory, które nie są jawnie wywoływane w main.cpp powinny być prywatne, podobnie jak współrzędne.

Proszę zaimplementować klasę Vector2D, reprezentującą wektor ma on 2 współrzędne i metody:
   - add, wylicza sumę dwóch wektorów
   - dot, wylicza iloczyn skalarny dwóch wektorów
   - print - wypisuje wektor
   - zwracające obiekt Vector2D na podstawie współrzędnych
  Ponadto możliwe jest zliczanie obiektów klasy.

UWAGA
  - Wymagane jest utworzenie konstruktora przenoszącego oprócz kopiującego ew. konstruktorów delegowanych (za ich brak są odejmowane punkty)
  - konstruktor przenoszący wypisuje wartość wektora przenoszonego do obiektu klasy przed przeniesieniem, jeśli wypisalibyśmy go po przeniesieniu, otrzymalibyśmy =(0,0), bo obiekt po prawidłowym przeniesieniu powinien się wyzerować
  - dla ułatwienia proszę skorzystać w konstruktorach z funkcji składowej print(std::string) - nie trzeba definiować dwóch funkcji print (parametry domyślne)
  - przypominam, że iloczyn skalarny oblicza się ze wzoru x1*x2+y1*y2
  - przeliczanie współrzędych biegunowych na kartezjańskie: [r*cos(α), r*sin(α)] M_PI to wartość liczby pi.
*/
#include <iostream>
#include "Vector2D.h"

Vector2D fun(Vector2D v) {
  return v;
}

int main() {
	{
		Vector2D v0("V0"); //nie ma potrzeby określania
    Vector2D v1 = Vector2D::fromCarthesian("V1", 2., 3.);		// (x, y)
		const Vector2D v2 = Vector2D::fromPolar("V2", 4., 30.);	// (promień, kąt w stopniach)

    v0.print("v0: ");
		v1.print("v1: ");
		v2.print("v2: ");
		std::cout << "\n*** ETAP 1 ***\nLiczba wektorow 2D: " << Vector2D::count << std::endl;

	 	double prod = v1.dot(v2);
	 	std::cout << "Iloczyn skalarny v1 i v2: " << prod << std::endl;
		
	  const Vector2D v3 = v1.add(v2); 
		v3.print("v3: ");
		std::cout << "Iloczyn skalarny v3,v1 " << v3.dot(v1) << ", v3,v2: " << v3.dot(v2) << std::endl;

	  Vector2D v4 = v2;
		v4.print("v4: ");
		std::cout << "\n*** ETAP 2 ***\nLiczba wektorow 2D: " << Vector2D::count << std::endl;

		Vector2D v5 (std::move(v3.add(v1)));
    Vector2D v6 = fun(Vector2D::fromCarthesian(2.5,3.5));
    Vector2D v7 = std::move(Vector2D("V7"));
		v5.print("v5: ");
    v6.print("v6: ");
    v7.print("v7: ");

    Vector2D v8 = std::move(v6);
    v8.print("v8: ");
    v6.print("v6: ");

    std::cout << "Liczba wektorow 2D: " << Vector2D::count << std::endl;
	}
	std::cout << "\n*** ETAP 3 ***\nLiczba wektorow 2D: " << Vector2D::count << std::endl;
}
/* oczekiwany wynik
./main
v0: V0=(0,0)
v1: V1=(2, 3)
v2: V2=(3.4641, 2)

*** ETAP 1 ***
Liczba wektorow 2D: 3
Iloczyn skalarny v1 i v2: 12.9282
v3: Vx=(5.4641, 5)
Iloczyn skalarny v3,v1: 25.9282, v3,v2: 28.9282
--- kopiowanie V2=(3.4641, 2)
v4: V2=(3.4641, 2)

*** ETAP 2 ***
Liczba wektorow 2D: 5
--- przenoszenie Vx=(7.4641,8)
--- przenoszenie V6=(2.5,3.5)
--- przenoszenie V7=(0,0)
v5: Vx=(7.4641,8)
v6: Vx=(2.5,3.5)
v7: V7=(0,0)
--- przenoszenie Vx=(2.5,3.5)
v8: Vx=(2.5,3.5)
v6: =(0,0)
Liczba wektorow 2D: 9

*** ETAP 3 ***
Liczba wektorow 2D: 0
*/