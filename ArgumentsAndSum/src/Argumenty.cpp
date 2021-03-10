
#include "Argumenty.h"
Argumenty::Argumenty(int a){
  tab=new double[a];
size=a;
}
Argumenty::~Argumenty(){
 delete [] tab;
  size=0;
}
void Argumenty::print(std::string data,std::ostream &a)const{
  a<<data;
  for(int i=0;i<size;i++){
    a<<" "<<tab[i];
  }
  std::cout<<std::endl;
}
Argumenty& Argumenty::operator()(int i, double data){
  tab[i]=data;
  return *this;
}