#include "studList.h"
#include <iostream>

int main() {
    std::cout << "*** Lista 1 ***" << std::endl;
    StudList list1("Lista1");

     Element* beata = new Element ("Beata");
     list1.prepend("Maria");
    list1.prepend(beata);
    list1.prepend("Agnieszka");

    StudList* ptr1 = &list1;
    std::cout << "Pierwszy: " << ptr1->getHead()->getName() << std::endl;
    std::cout << "Ostatni: ";
    ptr1->getTail()->printName();
    std::cout << std::endl;

    const StudList *ptrc=ptr1;
    std::cout << "Czy " << ptrc->getName() << " jest pusta? " 
              << (ptrc->isEmpty()?"Tak":"Nie") << std::endl;
    ptrc->print();

    std::cout << "\n*** Lista 2 ***" << std::endl;
    StudList list2("Lista2");
      
    Element tomasz("Tomasz");
    list2.prepend(&tomasz);
    list2.prepend("Krzysztof");
    list2.prepend("Adam");
   
    list2.print();

    std::cout << "\n*** Usuwanie ***" << std::endl;
    StudList* ptr2 = &list2;
    Element* PtrTomasz = ptr2->getLast();

     ptr2->print();
    std::cout << "--- Usuwam wszystkie elementy hurtem" << std::endl;
    list1.clearList();
    std::cout << "Czy " << list1.getName() << " jest pusta? " 
              << (list1.isEmpty()?"tak":"nie") << std::endl;
    std::cout << "--- Nazwa nadal istnieje, ale lista jest pusta" << std::endl;     
    list1.print();
    list1.prepend(PtrTomasz);
    ptr1->print();
    ptr1->getLast();
   list1.clearList(); //próba usunięcia pustej listy
    
    std::cout << "--- Usuwam listę element po elemencie" << std::endl;   

    list2.print();
    list2.removeLast();
    list2.print();
    list2.removeLast();
    list2.print();
    list2.removeLast();
 
    return 0;
}

/* //Output:

*** Lista 1 ***
Pierwszy: Agnieszka
Ostatni: Maria
Czy Lista1 jest pusta? Nie
Lista1 = [Agnieszka Beata Maria]

*** Lista 2 ***
Lista2 = [Adam Krzysztof Tomasz]

*** Usuwanie ***
Lista2 = [Krzysztof Tomasz]
--- Usuwam wszystkie elementy hurtem
Destruktor Element: kasowanie Agnieszka
Destruktor Element: kasowanie Beata
Destruktor Element: kasowanie Maria
Czy Lista1 jest pusta? tak
--- Nazwa nadal istnieje, ale lista jest pusta
Lista1 = []
Lista1 = [Adam]
--- Usuwam listę element po elemencie
Lista2 = [Krzysztof Tomasz]
Destruktor Element: Krzysztof
Lista2 = [Tomasz]
Destruktor Element: Tomasz
Lista2 = []
Destruktor Element: Adam
Destruktor StudList: Lista2
Destruktor StudList: Lista1
*/
