/* Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał
 * a wynik jego działania był taki sam, jak podany na końcu tego pliku.

 * Struktura MapPoint (pliki MapPoint.h, MapPoint.cpp) reprezentuje
 * punkt na mapie składający się z nazwy, długości (longitude)
 * i szerokości (latitude) geograficznej, bez oznaczania półkul.
 * Funkcje construct i clear to funkcje tworzące i usuwające punkt.
 * Funkcja movePoint zmienia współrzedne punktu, przesuwając go o wartości
 * podane w argumentach funkcji.
 
 * Funkcja inTheMiddle powinna tworzyć nowy punkt na mapie o zadanej
 * nazwie i położeniu, które jest średnią arytmetyczną z położeń
 * podanych punktów czyli x = (x1 + x2)/2 itp.

 * Struktura MapDist (pliki MapDist.h, MapDist.cpp)reprezentuje 
 * odległość pomiędzy dwoma punktami. 
 * Odległość wzdłuż południków lub równoleżników należy
 * obliczyć po prostu odejmując od siebie współrzędne punktów
 * początkowego i końcowego (funkcja distance).

 * Funkcja angularDistance oblicza pierwiastek z sumy kwadratów
 * odległości względem południków i równoleżników, czyli
 * sqrt(delta_x*delta_x + delta_y*delta_y). Funkcja obliczająca
 * pierwiastek nazywa się: sqrt(double) i znajduje się w bibliotece
 * "cmath".
 
 * Funkcja closestPlace pobiera 3 argumenty. Pierwszy argument jest
 * punktem referencyjnym. Z dwóch kolejnych wybiera ten, który jest
 * najbliżej punktu referencyjnego. Funcja wykorzystuje angularDistance

 * Proszę zadbać o dobre zarządzanie pamięcią.

 * Pliku main.cpp, nie wolno modyfikować.
 * Skonfiguruj plik konfiguracyjny cmake tak, aby:
 * - plikiem wynikowym był main
 * - program kompilował się z flagami -Wall -g - pedantic.
 * - były zdefiniowane cele użytkownika:
 *   run uruchamiający program i check uruchamiający valgrind ./main

 * Kody źródłowe powinny znajdować się w katalogu nazwisko_lab5 do którego nikt oprócz
 * właściciela nie ma praw dostępu.
 
 * UWAGA! Wysyłamy spakowany katalog nazwisko_lab5, nie oddzielne pliki! 
 * Wcześniej kasujemy niepotrzebne pliki z cmake wysyłamy tylko plik CMakeLists.txt.
 
 * Podczas wykonywania zadania nie wolno korzystać z internetu, notatek,
 * ani żadnych innych materiałów 
*/


#include <iostream>
#include "MapPoint.h"
#include "MapDist.h"

int main() {
  const double longitude = 19.938333;
  const double latitude = 50.061389;
  MapPoint* krk=construct("Kraków", latitude, longitude);
  print(krk);
  MapPoint* nyc     = construct("Nowy Jork", 40.7127, -74.0059 );
  print(nyc);
  MapPoint* porto   = construct("Porto", 41.162142, -8.621953 );
  MapPoint* irkutsk = construct("Irkuck",  52.283333, 104.283333);
  const MapPoint& siberiaCapital = *irkutsk;
  print(&siberiaCapital);

   const double longitudeShift = 4.1234;
   const double latitudeShift = -25.987;
   movePoint (irkutsk, latitudeShift, longitudeShift);
   std::cout<<"Po przesunięciu:\n";
   print (&siberiaCapital);

  const MapDist d = distance(*nyc, *porto);
   std::cout <<"Odległości między NYC i Porto: \nRóżnica szerokości: "<< d.latitude << " Różnica długości: " << d.longitude  << " " << "Odległość: "<<angularDistance(d) << std::endl;

  const MapPoint& cl = closestPlace(krk, porto, irkutsk);
  std::cout << "Najbliżej Krakowa jest " << getName(cl) << std::endl;

  MapPoint mp = inTheMiddle(krk, &siberiaCapital, "Gdzieś w Rosji");
  print(&mp);

  clear(krk, nyc, porto);
   clear(irkutsk);
}
/** Wynik działania programu:
Współrzędne dla Kraków. Długość: 50.0614. Szerokość: 19.9383
Współrzędne dla Nowy Jork. Długość: 40.7127. Szerokość: -74.0059
Współrzędne dla Irkuck. Długość: 52.2833. Szerokość: 104.283
Po przesunięciu:
Współrzędne dla Irkuck. Długość: 26.2963. Szerokość: 108.407
Odległości między NYC i Porto:
Różnica szerokości: -0.449444 Różnica długości: -65.3839 Odległość: 65.3855
Najbliżej Krakowa jest Porto
Współrzędne dla Gdzieś w Rosji. Długość: 38.1789. Szerokość: 64.1725
*/
