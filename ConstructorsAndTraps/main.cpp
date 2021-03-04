#include "MyList.h"
#include <iostream>


///////////////////////////////////////////////////////////////
// Funkcja służąca do opisu listy, sprawdzająca czy jest pusta,
// wypisująca długość listy i jej zawartość, wykorzystuje 
// funkcje składowe MyList: empty, size i print         
void describeList(const MyList & l);                        

// Funkcja generująca listę zawierającą liczby od 0 do n-1    
// (w celu pokazania konstrukotra przenoszącego)              
MyList generateList(int n);                                   

// Funkcje generujące kolejne wartości na podstawie poprzednich:
int genNextAdd(MyNode * node);                                
int genNextMul(MyNode * node);                                
///////////////////////////////////////////////////////////////


int main()
{  
    
    std::cout << "\n---> Konstruktor bezparametrowy <---" << std::endl;
    {
        // Tworzy pustą listę
        MyList l;
        describeList(l);    
    }
    
    std::cout << "\n---> Konstruktor jednoparametrowy <---" << std::endl;
    {
        // Tworzy listę kolejnych liczb, zaczynając od zera
        // Jest to konstruktor delegujący (tak jak i inne poniżej)
        MyList l(3);
        describeList(l);
        
        // Liste można wyczyścić przed destruktorem,
        // ale wciąż wszystko powinno działać.
        std::cout << "m.o.d.y.f.i.k.a.c.j.e" << std::endl;
        l.clear();
        describeList(l);
    }
    
    std::cout << "\n---> Konstruktor z lista inicjalizacyjna <---" << std::endl;
    {
        // Tworzy listę na podstawie przesłanej kombinacji
        // Konstruktor do napisania w oparciu o std::initializer_list<T>
        MyList l{1, 3, 5, 7, 9};
        describeList(l);
        
        // Po wyczyszczeniu listy, wciąż można dodawać elementy
        std::cout << "m.o.d.y.f.i.k.a.c.j.e" << std::endl;
        l.clear();
        describeList(l);
        l.add(77);
        describeList(l);
    }
    
    std::cout << "\n---> Uwaga na następujace pulapki <---" << std::endl;
    {
        // Różne pułapki
        MyList l();
        std::cout << "To nie jest konstrukcja obiektu: \"MyList l();\"" << std::endl;
        std::cout << "Nie wywolal się konstruktor! \"l\" to funkcja!" << std::endl;
                
        std::cout << "Konstrukcja przy uzyciu nawiasow okraglych:" << std::endl;
        MyList l1(3);
        describeList(l1);
        
        std::cout << "Konstrukcja przy uzyciu nawiasow klamrowych:" << std::endl;
        MyList l2{3};
        describeList(l2);
        
        std::cout << "Powstaly dwa obiekty o roznaych rozmiarach!" << std::endl;
    }
    
    std::cout << "\n---> Konstruktor kopiujacy <---" << std::endl;
    {
        // Konstruktor do skopiowania
        MyList l(3);
        describeList(l);
        
        MyList copy = l;
        describeList(l);
        describeList(copy);
        
        // Modyfikujemy bazę:
        std::cout << "m.o.d.y.f.i.k.a.c.j.e" << std::endl;
        l.add(8);
        describeList(l);
        describeList(copy);
    }
    
    std::cout << "\n---> Konstruktor przenoszacy <---" << std::endl;
    {   //Prosze użyć std::exchange  

        // Wykorzystanie funkcji generującej  
        MyList move = generateList(4);
        describeList(move);
        
        // Wykorzystanie std::move
        std::cout << "\nstd::move" << std::endl;
        MyList l(3);
        describeList(l);
        
        MyList stdmove = std::move(l);
        describeList(l);
        describeList(stdmove);
    }
    
    std::cout << "\n---> Uwaga na nastepujace pulapki <---" << std::endl;
    {     
        // Tutaj uwaga: sama funkcja generujaca nie wywołuje
        // ani konstruktora kopiującego ani przenoszącego!
        // Zadziałał mechanizm RVO: return value optimization
        generateList(5);
        std::cout << "Nie ma kopiowania!" << std::endl;
    }
    
    std::cout << "\n---> Skomplikowany konstruktor <---" << std::endl;
    {     
        // Tu nie ma niejasności, mimo różnicy w nawiasach wiadomo
        // który konstruktor wywołać
        MyList addL(genNextAdd, 5);
        describeList(addL);
        
        MyList addM{genNextMul, 5};
        describeList(addM);
        
    }
                
    return 0;
}

void describeList(const MyList & l)
{
    std::cout << "List: ";
    if(l.empty())
    {
        std::cout << "empty";
    }
    else
    {
        std::cout << "size = " << l.size();
    }
    std::cout << " : ";
    l.print();
}

MyList generateList(int n)
{
    MyList l(n);
    return l;
}

int genNextAdd(MyNode * node)
{
    return node ? node->val() + 2 : 0;
}

int genNextMul(MyNode * node)
{
    return node ? node->val() * 2 : 1;
}    

/* //Output:

---> Konstruktor bezparametrowy <---
KONST: Domyslny
List: empty : []
DESTRUKTOR (rozmiar = 0)

---> Konstruktor jednoparametrowy <---
KONST: Domyslny
KONST: Jednoargumentowy
List: size = 3 : [0, 1, 2]
m.o.d.y.f.i.k.a.c.j.e
List: empty : []
DESTRUKTOR (rozmiar = 0)

---> Konstruktor z lista inicjalizacyjna <---
KONST: std::initializer_list
List: size = 5 : [1, 3, 5, 7, 9]
m.o.d.y.f.i.k.a.c.j.e
List: empty : []
List: size = 1 : [77]
DESTRUKTOR (rozmiar = 1)

---> Uwaga na następujace pulapki <---
To nie jest konstrukcja obiektu: "MyList l();"
Nie wywolal się konstruktor! "l" to funkcja!
Konstrukcja przy uzyciu nawiasow okraglych:
KONST: Domyslny
KONST: Jednoargumentowy
List: size = 3 : [0, 1, 2]
Konstrukcja przy uzyciu nawiasow klamrowych:
KONST: std::initializer_list
List: size = 1 : [3]
Powstaly dwa obiekty o roznaych rozmiarach!
DESTRUKTOR (rozmiar = 1)
DESTRUKTOR (rozmiar = 3)

---> Konstruktor kopiujacy <---
KONST: Domyslny
KONST: Jednoargumentowy
List: size = 3 : [0, 1, 2]
KONST: Domyslny
KONST: kopiujacy
List: size = 3 : [0, 1, 2]
List: size = 3 : [0, 1, 2]
m.o.d.y.f.i.k.a.c.j.e
List: size = 4 : [0, 1, 2, 8]
List: size = 3 : [0, 1, 2]
DESTRUKTOR (rozmiar = 3)
DESTRUKTOR (rozmiar = 4)

---> Konstruktor przenoszacy <---
KONST: Domyslny
KONST: Jednoargumentowy
List: size = 4 : [0, 1, 2, 3]

std::move
KONST: Domyslny
KONST: Jednoargumentowy
List: size = 3 : [0, 1, 2]
KONST: przenoszacy
List: empty : []
List: size = 3 : [0, 1, 2]
DESTRUKTOR (rozmiar = 3)
DESTRUKTOR (rozmiar = 0)
DESTRUKTOR (rozmiar = 4)

---> Uwaga na nastepujace pulapki <---
KONST: Domyslny
KONST: Jednoargumentowy
DESTRUKTOR (rozmiar = 5)
Nie ma kopiowania!

---> Skomplikowany konstruktor <---
KONST: funkcja generujaca
List: size = 5 : [0, 2, 4, 6, 8]
KONST: funkcja generujaca
List: size = 5 : [1, 2, 4, 8, 16]
DESTRUKTOR (rozmiar = 5)
DESTRUKTOR (rozmiar = 5)

*/
