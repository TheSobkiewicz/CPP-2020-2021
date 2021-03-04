#include "studList.h"
StudList::StudList(const char *data)
{
name=data;
tail=nullptr;
head=nullptr;
}
void StudList::prepend(const char *data)
{
  Element *add=new Element(data);
  if(!head)
  {
    head=add;
    tail=add;
  }
  else{
    add->setnext(head);
    head=add;
  }
}
void StudList::prepend(Element *add)
{
   if(!head)
  {
    head=add;
    tail=add;
  }
  else{
    add->setnext(head);
    head=add;
  }
}
Element* StudList::getHead()
{
  return head;
}
Element* StudList::getTail()
{
  return tail;
}
bool StudList::isEmpty()const 
{
  if(head) return false;
  else return true;
}
const char* StudList::getName()const
{
  return name;
}
void StudList::print()const
{

std::cout<<name<<" = "<<"[";
Element *cur=head;
while(cur!=tail)
{
  cur->printName();
  std::cout<<" ";
  cur=cur->getnext();
}
if(cur)std::cout<<cur->getName();
std::cout<<"]\n";
}
Element* StudList::getLast()
{
  Element *temp=tail;
  if(head==tail)
  {
    tail=nullptr;
    head=nullptr;
    return temp;
  }
  Element *cur=head;
  while(cur->getnext()!=temp)cur=cur->getnext();
  cur->setnext(nullptr);
  tail=cur;
  return temp;
}
void StudList::clearList()
{
Element *cur=head;
Element *next=cur;
while(cur && cur != tail)
{
  next=cur->getnext();
  delete cur;
  cur=next;
}
delete tail;
head=nullptr;
tail=nullptr;
}
void StudList::removeLast()
{
  delete getLast();
}
StudList::~StudList()
{
  std::cout<<"Destruktor Element: kasowanie "<<name<<std::endl;
}
