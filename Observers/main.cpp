/*
 Celem zadania jest obsluzenie sytuacji, w ktorej mamy wiele klas, w ktorych zmieniaja sie dane (Obserwowani) i wiele klas, w ktorych te dane chcemy monitorowac (Obserwatorzy).
  W zadaniu podano przyklady klas obserowanych natomiast klas(a/y) bazowe sa do na pisania. 
  Do napisania jest takze hierachia klas obserwatorow.
  
  UWAGA: W pzypadku, gdy dwie hierarchie klas musza ze soba wspolpracowac 
  programujemy te interakcje z uzyciem metod klas bazowych 
  (najczesciej czysto abstrakcyjnych).

  UWAGA: W zadaniu nie trzeba kopiowac klas obserwatorow. 
 */

#include <iostream>
#include "Obserwowany.h"
#include "Obserwator.h"

class DaneOdUsera : public Obserwowany {
public:
  DaneOdUsera()
    : m_licznik(0) {}
  
  void odczytaj( int x) {
    m_dane[m_licznik] = x;
    ++m_licznik;
    noweDaneNadeszly(x);
  }
  
private:
  int m_dane[10];
  int m_licznik;  
};

class Generator : public Obserwowany {
public:
  Generator(int init)
    : m_c(init) {}
  int nastepna() {  
    noweDaneNadeszly(m_c);
    m_c++;
    return m_c - 1;
  }
private:
  int m_c;
};


int main() {

  ObserwatorLicznik ol1;
  ObserwatorLicznik ol2;
  ObserwatorWypisywacz ow;

  DaneOdUsera du;
  du.odczytaj(9);
  du.dodajObserwatora( &ol1 );
  du.dodajObserwatora( &ow );
  du.odczytaj(2018);
  du.odczytaj(9);
  du.odczytaj(1);
  
  std::cout << "\ng1\n";
  Generator g1(0);
  g1.dodajObserwatora( &ol2 );
  g1.dodajObserwatora( &ow );  
  

  g1.nastepna();
  g1.nastepna();
  g1.nastepna();
  g1.nastepna();
  g1.nastepna();
  std::cout << "\ng2\n";
  Generator g2(100);
  du.dodajObserwatora( &ow );
    
  
  std::cout << g2.nastepna() << " " << g2.nastepna() << std::endl;
  std::cout << "sumy " << ol1.suma() << " " << ol2.suma() << std::endl;
  
}
/* wynik
 2018 9 1
g1
 0 1 2 3 4
g2
100 101
sumy 2028 10

 */
