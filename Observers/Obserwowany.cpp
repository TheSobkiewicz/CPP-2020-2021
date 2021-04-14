#include "Obserwowany.h"

void Obserwowany::noweDaneNadeszly( int x )const {
  for(auto i : vec) {
    i->doYourJob(x);
  }
}

void Obserwowany::dodajObserwatora( Obserwator *o ) {
  vec.push_back(o);
}