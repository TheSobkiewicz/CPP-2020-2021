
/* Zdefiniowana jest klasa Person, ktora rozroznia plec ( posiada skladnik bool rozrozniajacy ).
   
  Do napisania jest Qulturalna Koleja.  Kolejka ta puszcza przodem kobiety (to znaczy respektuje zadany proprytet).
   
  W implementacji nalezy uzyc std::list.
  Spryt jest wymagany jedynie przy implementacji metody "dodaj".
  Logika powinna byc nastepujaca:
   - jesli juz cos jest to przegladamy elementy jeden po drugim i porownujemy klucze
      klucz_wlasnie_dodawanego < klucz_elemetu_w_liscie
      Przy pierwszym elemencie w liscie, dla ktorego to prawda umieszczemy nowy element przed nim. (metoda insert)
   - jesli w liscie nie ma zadnych elementow to wiadomo co trzeba zrobic.
    
  UWAGA: Prosze nawet nie myslec o definiowaniu wlasnych iteratorow.

  Jako zadanie domowe prosze przerobic zadanie tak by uzyc dedykowanego specjalnego kontenera priority_queue.
 */ 

#include "QKolejka.h"
#include "Person.h"

int main() {
  // ciekawy konstruktor tu mamy! 
  // Mianowicie dostarczamy obiektowi pewnej funkcji odpowiadajacej za uszeregowanie (priorytet) w kolejce
  QKolejka<Person> kolejka( [](const Person& p) -> int { return (p.isWoman() ? 0 : 1); } );

  kolejka.dodaj( Person::kobieta( "Anna" ) );
  kolejka.dodaj( Person::mezczyzna( "Janek" ) );
  kolejka.dodaj( Person::kobieta( "Ewa" ) );
  kolejka.dodaj( Person::kobieta( "Kasia" ) );
  kolejka.dodaj( Person::kobieta( "Aisha" ) );
  kolejka.dodaj( Person::mezczyzna( "Grzegorz" ) );
  kolejka.dodaj( Person::mezczyzna( "Tomasz" ) );
  kolejka.dodaj( Person::kobieta( "Stanislawa" ) );

  for ( const auto& p: kolejka ) { // co jest potrzebne zeby range-for zadzialal?
    std::cout << p << " ";
  }
  std::cout << std::endl;

  kolejka.dodaj( Person::mezczyzna( "Rysiek" ) );
  kolejka.dodaj( Person::kobieta( "Iza" ) );

  // to jest wypisanie w odwrotnej kolejnosci
  for ( QKolejka<Person>::const_reverse_iterator i = kolejka.rbegin(); i != kolejka.rend(); ++i ) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;

  QKolejka<int> inty( [](int x){ return -x; });
  inty.dodaj({3,4,5,6,1,4,2,-1}); // lista inicjalizacyjna umozliwia dodanie wielu ementow na raz
  for ( const auto& p: inty ) {
    std::cout << p << " ";
  }
  std::cout << std::endl;

  const QKolejka<Person>& ck = kolejka;
  std::cout << *ck.begin() << " "<< *std::begin(ck) << std::endl;

}
/* wynik
Anna K Ewa K Kasia K Aisha K Stanislawa K Janek M Grzegorz M Tomasz M
Rysiek M Tomasz M Grzegorz M Janek M Iza K Stanislawa K Aisha K Kasia K Ewa K Anna K
6 5 4 4 3 2 1 -1
Anna K Anna K
*/
