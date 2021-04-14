#pragma once
#include <iostream>
#include <vector>
#include "Obserwator.h"
class Obserwowany {//podstawowa klasa w hierarchi obserwowanych, umozliwiajaca interakcje z Obserwatorami.
   public:

   void noweDaneNadeszly( int x )const;// funckja informujaca wszystkich Obserwatorów z vectora vec iż nadeszły nowe dane i trzeba na nie zareagować.

   void dodajObserwatora( Obserwator *o );// funckja dodajaca obiekt klasy Obserwator do vectora vec, jako że dodaje ona wskaźniki, to o zarządzanie pamięcią trzeba zadbać w funkcji w której została ona wywołana ( w tym przypadku main).

   private:

  std::vector<Obserwator*> vec;//vector Obserwatorów reagujących na działania tego obiektu

};