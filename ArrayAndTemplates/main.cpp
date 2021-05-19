/* W zadaniu nalezy napisac szablon klasy Array ze specjalizacjami wartosci i dla wskaznikow.
   Specjalizacja wplywa na kilka aspektow dzialna tego szablonu. 
   W szczegolscnosci na to co robi   destruktor (czy kasuje obiekty, czy nie). 
   Zmieniaja sie takze operator[] i operator <<.
   Klasa X jest trywialnie prosta: przechowuje napis, dostarcza metody dostepowej, a podczas destrukcji wypisuje przechowywany napis.
   Klasa Y dziedziczy po X i rozni sie tylko .
 */

#include <iostream>
#include <stdexcept>
#include "Array.h"

#include "X.h"


int main() {
  {
    Array<7, int> iArray;
    iArray[0] = 0;
    iArray[1] = 8;
    iArray[3] = 6;
    std::cout << iArray << std::endl;
  }

  {
    Array<4, X> xArray;
    xArray[0] = X("a0");
    xArray[2] = X("a2");
    
    std::cout << "Xarr: " << xArray << std::endl;
  }
  {
    Array<5, X*> xPtrArray;
    xPtrArray[0] = new X("obj 0 ");
    xPtrArray[1] = new X("obj 1 ");
    xPtrArray[2] = new X("obj 2 ");
    xPtrArray[3] = new Y("obj Y 0 ");
    std::cout <<  "XArr ptr: " << xPtrArray << std::endl;
  }  
}
/* wynik
0 8 0 6 0 0 0
deleting X a0
deleting X a2
Xarr: a0  a2
deleting X
deleting X a2
deleting X
deleting X a0
XArr ptr: obj 0  obj 1  obj 2  obj Y 0
deleting X obj 0
deleting X obj 1
deleting X obj 2
deleting Y obj Y 0
deleting X obj Y 0
 */
