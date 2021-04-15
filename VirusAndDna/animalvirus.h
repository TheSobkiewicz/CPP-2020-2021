#pragma once
#include "virus.h"
class AnimalVirus : public Virus  {

  public:
	AnimalVirus(string virus, string animal, std::vector< Nukleotyp > seq);
  string get_animal_host(); 
  AnimalVirus()=default;
  AnimalVirus( AnimalVirus& other);
  AnimalVirus(AnimalVirus&& other);
  AnimalVirus& operator = (AnimalVirus &&dummy);
  private:
  string animalName;
};