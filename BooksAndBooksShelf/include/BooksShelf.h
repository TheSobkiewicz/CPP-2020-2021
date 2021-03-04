#include"Book.h"
class BooksShelf
{
Book *shelf;
 int size;
int counter;
public:
  BooksShelf(int data);//Konstruktor, tworzy nowy obiekt i przypisuje data do zmiennej size
  ~BooksShelf();//Destruktor, usuwa klase
  void add(Book add);//Dodaje obiekt add na pierwsze wolne miejsce w tablicy shelf
  void print()const;//wypisuje nazwy obiektow book w tablicy shelf
  void remove(int which);//usuwa element o indeksie which z tablicy shelf
};