
/*----------------------------------------------------------------
W zadaniu malezy zaimplementowac przetwarzanie liczb typu double (upakowanych w klase Argumenty znana z poprzedniego zadania).

Sekwencja przetwarzania (kolejne kroki) sa tworzone dynamicznie (w czasie wykonania programu)!

W implementacji, jesli ktos umie, moze uzyc std::vector, 
   w przeciwnym razie mozna zalozyc jakis maksymalny rozmiar w klasach Argumenty i w SekwencjaAlgorytmow.
Mozna tez zrobic list polaczona algoorytmow.

UWAGA: Prosze sie bacznie przygladnac argumentom przyjmowanym przez metode SekwencjaAlgorytmow::add, 
       czy mozemy znalezc dla nich "wspolny mianownik"?   
UWAGA: Standard, poprawnosc const.

*/


#include "Argumenty.h"
#include "SekwencjaAlgorytmow.h"
#include "Algs.h"


struct Printer{
    Printer(const char* prefix) : m_prefix{prefix} {}
    Argumenty operator()(const Argumenty& arg) const {
        std::cout << m_prefix << arg << std::endl;
        return arg;
    }
    const char* m_prefix;
};

int main() {
    SekwencjaAlgorytmow kwadratNajmniejszej;
    kwadratNajmniejszej.add( Printer("Wejscie ") );
    kwadratNajmniejszej.add(minimum);
    kwadratNajmniejszej.add([](const Argumenty& a){ std::cout << "1 " << a << std::endl; return a;});
    kwadratNajmniejszej.add([](const Argumenty& a){ return Argumenty::pojedynczy(a[0]*a[0]); });
    // w domu prosze dodac sobie funkcjonalnosc usunieca, ktoregos kroku, i dodania kroku miedzy dwoma innymi
    // prosze dodac mozliwosc opuszenia kolejnych krokow obliczen

    Argumenty a(3);
    a(0, 4)(1, -2)(2, 6);
    const Argumenty a2(a); // upewniam sie czy jest to kopiowalny obiekt, w domu prosze dodac mozliwosc przesuwania

    auto wynik = kwadratNajmniejszej.procesuj(a2);
    std::cout <<  "Wynik " << wynik << std::endl;

    const Argumenty a3(a2);
    SekwencjaAlgorytmow kwadratSumy;
    kwadratSumy.add(sum);
    kwadratSumy.add(sq);

    wynik = kwadratSumy.procesuj(a3);
    std::cout << "Wynik " << wynik << std::endl;

}
/* wynik
Wejscie 4 -2 6
1 -2
Wynik 4
Wynik 2.82843
*/