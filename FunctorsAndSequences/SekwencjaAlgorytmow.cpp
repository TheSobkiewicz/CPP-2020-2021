#include "SekwencjaAlgorytmow.h"

void SekwencjaAlgorytmow::add (std::function< Argumenty (const Argumenty&)> fun) {
  vec.push_back(fun);
}

Argumenty SekwencjaAlgorytmow::procesuj (const Argumenty &a)const {
  Argumenty b=a;
  for (std::function<Argumenty(const Argumenty&)>n:vec) {
    b=n(b);
  }
  return b;
}