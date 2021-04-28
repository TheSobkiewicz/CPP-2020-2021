#pragma once
#include <cmath>
#define MyCalculation(className, firstBase, secondBase) \
class className : public firstBase, public secondBase { \
public : \
void eval(int arg)const { \
double value =sqrt( pow(arg - 7, 2) ); \
if(!hasCacheFor(arg)) {\
  cacheValueForArgument(arg,value); \
  printArgAndResult(arg,value); \
  } \
} \
};

//deklarujemy makro tworzące nowe klasy w oparciu o podane argumenty