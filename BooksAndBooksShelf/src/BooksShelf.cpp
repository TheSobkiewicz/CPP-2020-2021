#include "BooksShelf.h"
BooksShelf::~BooksShelf()
{
  delete []shelf;
}
BooksShelf::BooksShelf(int data)
{
  shelf=new Book[data];
  size=data;
  counter=0;
}
void BooksShelf::add(Book add)
{
  shelf[counter]=add;
  counter++;
}
void BooksShelf::print()const
{
  unsigned int max=0;
  for(int i=0; i<counter;i++)
  {
    if(max<shelf[i].title.length())max=shelf[i].title.length();
  }
  for(int i=0;i<counter;i++)
  {
    for(unsigned int j=0;j<(max-shelf[i].title.length())/2;j++)std::cout<<" ";
    std::cout<<shelf[i].title<<std::endl;
  }
}
void BooksShelf::remove(int which)
{
  
  if(which<counter)
  {
    counter--;
    Book *change= new Book[counter];
  for(int i=0,j=0;i<counter;i++,j++)
  {
    if(j==which)j++;
    change[i]=shelf[j];
  }
  shelf=change;
  }
  else 
  std::cout<<"!!! Nie mozna usunac ksiazki spoza polki !!! (element "<<which<<")\n";
}