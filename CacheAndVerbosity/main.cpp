/*
W zadaniu będziemy definiowac i uzywac wymiennych "polityk"/zchowan do modyfikacji zlozonych zachowan klasy. 
Mianowicie mamy polityke dotyczaca "cachowania" czyli zapamietywania wynikow posrednich: 
Ta polityka definiowana jest poprzez nastepujace metody:
struct CachePolicy : public Policy {
    virtual void cacheValueForArgument( double arg, double val ) const = 0; // zapamietuje warosc obliczenia dla argumentu
    virtual bool hasCacheFor( double arg ) const = 0;  // zwraca true jesli w cachu znajduje sie wartosc dla argumentu
    virtual double getCached(double arg) const = 0; // zapamietana wartosc dla argumentu
};
Ta abstrakcyjna polityka posiada dwie implementacje: NoCache i OneCallCache.
Pierwsza z nich niczego nie zapamietuje. Druga zapamietuje tylko jedna liczbe, z ostatniego wywolania.


Druga polityka dotyczy tego czy przy obliczeniu cos ma byc wypisuwane na ekran.
struct VerbosityPolicy : public Policy {
    virtual void printArgAndResult( double arg, double val) const = 0; // wypisuje na stdout argument i wynik dzialania na tym argumencie
};
Dwie implementacje tej polityki to Silent i Verbose

Takie polityki mozemy uzyc nastepujaco:
typedef NoCache UsedCachePolicy;
typedef Verbose UsedVerbosityPolicy;
class X : public UsedCachePolicy, public UsedVerbosityPolicy {
    void jakiesObliczenie(double arg) {
        // uzywamy tutaj powyzszych polityk np.
        double result = ..........
        printArgAndResult(ar, result);
        //....
    }
}
W ten sposob mozemy latwo w calym programie zmienic zachowanie zmieniajac polityke w jednym miejscu. 
T.j. redefinujac:
typedef Silent UsedVerbosityPolicy;


Aby to zadanie mialo sens na laboratorium umozliwany generacje wielu klas z roznymi wariantami polityk. 
Sluzy na do tego makro MyCalculation generujace klase o zadaniej w ARG 1 nazwie i odpowiednimi klasami polityk zadanymi w ARG 2 i 3.

UWAGA: Samo oblicznie w MyCalculation to:
sqrt( pow(arg - 7, 2) );

UWAGA: wielolinijkowe makrodefinicje piszemy tak (\ sluzy do kontynuacji w nowej linii):
#define max(a, b, c) \
        a = b; \
        if ( b > a ) \
        a = c;  
UWAGA: Wszystkie niewirtualne polityki maja metode policyName zwracajaca nazwe (std::string lub const char*) polityki  
*/


#include <cmath>
#include <iostream>

#include "Policy.h"

#include "MyCalculation.h" // tu znajduje sie makrodefinicja, ktora uzwyajac w.w. polityk moze generowac rozne klasy


int main() {
    MyCalculation(Calc1, NoCache, Verbose) // tu generujemy klase Calc1
    Calc1 c1; // twozymy obiekt wlasnie wygenerowanej klasy
    c1.eval(5); // wywolujemy metode tej klasy

    MyCalculation(Calc2, OneCallCache, Verbose) // tu generujemy klase Calc2
    Calc2().eval(4); // tworzymy chwilowy obiekt i wywolujemy na nim metode
    Calc2 c2;
    c2.eval(9);
    c2.eval(9); // tutaj obliczenie sie nie odbywa, wiec nic nie jest wypisane
    c2.eval(7); // inny argument, wiec oblicznie sie odbywa
    std::cout <<  static_cast<CachePolicy&>(c2).policyName() << " " << static_cast<VerbosityPolicy&>(c2).policyName() << std::endl;



    MyCalculation(Calc3, OneCallCache, Silent) // tu generujemy klase Calc3
    Calc3().eval(3); // brak wyniku na ekranie, polityka Silent
    c2.eval(3);
}
/* wynik
f(5) = 2
f(4) = 3
f(9) = 2
f(7) = 0
OneCallCache Verbose
f(3) = 4
*/