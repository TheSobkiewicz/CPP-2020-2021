#pragma once 
#include <iostream>
class BooksShelf;
class Book
{
std::string title;
friend class BooksShelf;

public:
  Book(std::string data);//konstruktor przypisujący string data do zmiennej title
  Book();//domyślny konstruktor- ustawia nazwe ksiazki na ""
};