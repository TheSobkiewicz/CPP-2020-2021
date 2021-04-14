#include "Obserwator.h"

void ObserwatorLicznik::doYourJob( int x ) {
  sum += x;
}

int ObserwatorLicznik::suma() {
  return sum;
}

void ObserwatorWypisywacz::doYourJob( int x ) {
  std::cout << " " << x; 
}