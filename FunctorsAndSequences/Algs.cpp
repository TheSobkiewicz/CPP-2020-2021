#include "Algs.h"
#include "math.h"
Argumenty minimum (const Argumenty &a) {
  double min=a[0];
  for(int i=1;i<a.rozmiar();i++) {
    if(a[i]<min)min=a[i];
  }
  return Argumenty::pojedynczy(min);
}

Argumenty sq (const Argumenty &a) {
  return Argumenty::pojedynczy(sqrt(a[0]));
}

Argumenty sum (const Argumenty &a) {
double sum=0;
  for(int i=0;i<a.rozmiar();i++) {
    sum+=a[i];
  }
  return Argumenty::pojedynczy(sum);
}