#include "Element.h"
const char * Element::getName()
{
  return name;
}
void Element::printName()
{
  std::cout<<name;
}
Element::Element(const char *data)
{
  name=data;
  next=nullptr;
}
Element::~Element()
{
  std::cout<<"Destruktor Element: kasowanie "<<name<<std::endl;
}
Element* Element::getnext()
{
  return next;
}
void Element::setnext(Element *data)
{
next=data;
}