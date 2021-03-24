
#include "Argumenty.h"

Argumenty& Argumenty::operator()(int i, double data) {
  vec[i]=data;
  return *this;
}

Argumenty::Argumenty(int n){
  for(int i=0;i<n;i++){
    vec.push_back(0);
  }
}  

std::ostream& operator <<(std::ostream &a,const Argumenty &arg) {
  for(double n:arg.vec){
    a<<n<<" ";
  }
return a;
}

Argumenty Argumenty::pojedynczy(double data) {
  Argumenty n(1);
  n(0,data);
  return n;
}
