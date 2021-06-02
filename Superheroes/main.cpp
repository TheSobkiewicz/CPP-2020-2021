  /**
 * Celem zadania jest napisanie, z uzyciem konetenerow i algorytmow standardowych 
 * klasy Team i struktury member. Funkcjonalnosc ma byc taka jak to wynika z "outputu".
 *
 * UWAGA: w zadaniu nie moze sie zalezc zadna tradycyjna petla, wszystko trzeba zrobic za pomoca algorytmow STLa
 * UWAGA: std::set (jak ktos chce go uzyc) nie wspolpracuje z algorytmem remove_if, trzeba zrobic kopie w innym kontenerze i tam zrobic remove_if. 
 **/
#include "Member.h"
#include "Team.h"

int main() {
  Team t1;
  t1.add(  Member("Atos").power(7).magic(5).health(7) );
  t1.add(  Member("Portos").power(3).magic(5).health(2) );
  t1.add(  Member("Aramis").power(2).magic(9).health(6) );
  t1.add(  Member("Aramis").power(2).magic(9).health(6) );
  t1.add(  Member("Mr. B").power(4).magic(0).health(5) );
  std::cout << t1;
  std::cout << "--\n";
  Team t2;
  t2.add(  Member("Mr. B").power(4).magic(0).health(5) );
  t2.add(  Member("Frodo").power(1).magic(2).health(3) );
  t2.add(  Member("Gandalf").power(8).magic(10).health(3) );  
  std::cout << t2;
  std::cout << "--\n";
  
  
  
  Team common = t2 - t1;
  std::cout << common;
  std::cout << "--\n";
  Team super_team = t1 + t2;
  std::cout << super_team;
  std::cout << "--\n";
  super_team.kill( [](const Member&  m){ return m.magic() <= 2; } );
  std::cout << super_team;
  
}
/* wynik
Aramis power:2 magic:9 health:6
Atos power:7 magic:5 health:7
Mr. B power:4 magic:0 health:5
Portos power:3 magic:5 health:2
--
Frodo power:1 magic:2 health:3
Gandalf power:8 magic:10 health:3
Mr. B power:4 magic:0 health:5
--
Mr. B power:4 magic:0 health:5
--
Aramis power:2 magic:9 health:6
Atos power:7 magic:5 health:7
Frodo power:1 magic:2 health:3
Gandalf power:8 magic:10 health:3
Mr. B power:4 magic:0 health:5
Portos power:3 magic:5 health:2
--
Aramis power:2 magic:9 health:6
Atos power:7 magic:5 health:7
Gandalf power:8 magic:10 health:3
Portos power:3 magic:5 health:2

 */
