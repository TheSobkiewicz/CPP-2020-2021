/*
Celem zadania jest napisanie szablonu listy polaczonej.
Ma to byc najprostsza lista, to znaczy polaczona jednokierunkowo.
Z roznych operacji, ktore oferuje lista potrzebne sa tylko:
add - dodajaca na koniec
contains - sprawdzajaca czy element o zadanej wartosci jest w liscie

+ operacje kopiowania i przesuwania listyi destruktor

Polecam do zrobienia w domu (znaczy ze moze bedzie na kolejnych laborkach):
dodanie operacji pop (zwracjacej ostatni element i usuwajacy go z listy)
dodanie operacji contains z predykatem. np l1.contains( [](int x){ return x > 5; } )
dodanie operacji collect z predykatem . l1.collect( [](int x){ return x > 5; } ) // zwraca liste z elemetnami wiekszymi niz 5
dodanie przesuwajacego operator przypisania

UWAGA: prosze pamietac o porawnosci const (przyklad jej nie wymusza ala ja sprawdze)
UWAGA: kod metod moze sie znajdowac w ciele klasy (prosze sobie w domu przepisac rozwiazanie take zeby metody byly poza klasa)

*/
#include <string>
#include <utility>
#include <iostream>

#include "List.h"
int main() {
    List<int> l1;
    l1.add(1).add(6).add(6).add(11).add(7);
    std::cout << "orginal " << l1 << std::endl;
    List<int> l2 = l1;
    std::cout << "kopia " << l2 << std::endl;
  
    List<int> l3(std::move(l1));
    std::cout << "orginal po przesunieciu "<< l1 << std::endl;
    std::cout << "w nowym miejscu "<< l3 << std::endl;
    std::cout << "Jest 3? " << l3.contains(7) << " A jest 6? "<<l3.contains(16) << std::endl;


    List<std::string> s;
    s.add("Hello").add("darkness").add("my").add("old").add("friend");
    std::cout << s << std::endl;

}
/* wynik
orginal 1 6 6 11 7
kopia 1 6 6 11 7
orginal po przesunieciu
w nowym miejscu 1 6 6 11 7
Jest 3? 1 A jest 6? 0
Hello darkness my old friend
*/




