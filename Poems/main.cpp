 /* Zadanie 12: Pisanie wierszy
 * 
 * Do napisania są dwie klasy: MyLine i prosty kontener na nią:
 * MyPoem, która ma określoną liczbe wierszy. 
 * 
 * Należy zdefiniować odpowiednie konwersje: const char * <-> MyLine;
 * oraz zabronić konwersji które nie powinny móc zajść: int -> MyPoem. 
 * 
 * UWAGA: W zadaniu nie wolno korzystać z gotowych kontenerów, 
 * poza użyciem std::string go przechowywania danej linijki tekstu
 * (MyPoem musi alokować pamięć dynamicznie operatorem new).
 * 
 * -------------------------------------------------------------------
 * Fragment wiersza pochodzi z utworu J. Słowackiego: "Testament mój",
 * od którego wzieła swój tytuł książka Aleksandera Kamińskiego 
 * "Kamienie na szaniec". 
 */

#include "MyLine.h"
#include "MyPoem.h"
#include <iostream>

void convertAndPrint(const char * line)
{
    std::cout << line << std::endl;
}

void printHeaderInColor(const char * line)
{
    std::cout << "\033[1;31m\n" << line << "\033[0m" << std::endl;
}

int main()
{  
    std::cout << "Rozpoczynamy zadanie 12: Pisanie wierszy!" << std::endl;
    
    // Rozgrzewka
    MyLine       l0{"Lecz zaklinam: niech zywi nie traca nadziei"};
    MyLine       l1 = "I przed narodem niosa oświaty kaganiec;";
    const MyLine l2("A kiedy trzeba, na smierc ida po kolei,");
    auto         l3 = MyLine{"Jak kamienie, przez Boga rzucane na szaniec!"};

    printHeaderInColor("--------> Rogrzewka <---------");   
    convertAndPrint(l0);
    convertAndPrint(l2);

    // Pisanie wiersza
     #ifdef MY_ERROR_EXPECTED
       MyPoem draft = 4; // nie może się skompilować
     #else
        MyPoem draft = static_cast<MyPoem>(4);
    #endif
    draft.setLine(0, l0);
    draft.setLine(1, l1);
    draft.setLine(2, l2);
    draft.setLine(3, l3);

    printHeaderInColor("------> Wersja robocza <------");
    draft.print();
    
    // Kopia zapasowa
    const MyPoem copy = draft;
    draft.setLine(1, ".....");
    
    printHeaderInColor("------> Wersja robocza <------");
    draft.print();
    printHeaderInColor("----------> Kopia <-----------");
    copy.print();
    
    // Przeniesienie wiersza do ksiazki
    MyPoem book = std::move(draft);
    
    printHeaderInColor("------> Wersja robocza <------");
    draft.print();
    printHeaderInColor("-----> Wiersz w ksiazce <-----");
    book.print();

    return 0;
}

/************************* OUTPUT ***********************
Rozpoczynamy zadanie 12: Pisanie wierszy!

--------> Rogrzewka <---------
Lecz zaklinam: niech zywi nie traca nadziei
A kiedy trzeba, na smierc ida po kolei,

------> Wersja robocza <------
Lecz zaklinam: niech zywi nie traca nadziei
I przed narodem niosa oświaty kaganiec;
A kiedy trzeba, na smierc ida po kolei,
Jak kamienie, przez Boga rzucane na szaniec!

------> Wersja robocza <------
Lecz zaklinam: niech zywi nie traca nadziei
.....
A kiedy trzeba, na smierc ida po kolei,
Jak kamienie, przez Boga rzucane na szaniec!

----------> Kopia <-----------
Lecz zaklinam: niech zywi nie traca nadziei
I przed narodem niosa oświaty kaganiec;
A kiedy trzeba, na smierc ida po kolei,
Jak kamienie, przez Boga rzucane na szaniec!

------> Wersja robocza <------

-----> Wiersz w ksiazce <-----
Lecz zaklinam: niech zywi nie traca nadziei
.....
A kiedy trzeba, na smierc ida po kolei,
Jak kamienie, przez Boga rzucane na szaniec!
**********************************************************/