#pragma once
#include <iostream>

// klasa reprezentujaca osobę
class Person
{
public:
// konstruktor - lista inicjalizacyjna
    explicit Person(std::string& name, bool hair = true, bool isman = true) 
	: _name(name), _haircut(hair), _man(isman) {}

    virtual ~Person() = default;

// gettery 
    std::string name() const {return _name;}
    bool is_man() const { return _man;}

// strzyzenie
    void haircut()
    {
        if(_haircut) _haircut = false;
        else std::cout << "\n!!! Klient juz ostrzyzony !!!";
    }

// funkcje wirtualne 
    virtual void print() const = 0;
    virtual bool done() const = 0; // czy gotowy do opuszczenia zakładu
    virtual void makeup() = 0;  // dla kobiet
    virtual void shave() = 0;   // dla mężczyzn 


protected: 
    std::string _name;
    bool _haircut; // true - wymaga strzyzenia false - nie wymaga strzyżenia
    bool _man; // kobieta -> false, mezczyzna -> true
};