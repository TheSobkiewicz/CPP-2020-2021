#pragma once

namespace Functors {

class Functors {
  public:
  Functors(int num): number(num){}

  virtual bool operator()(int n) = 0;

  protected:
    int number;
};

class divisibleBy: public Functors {
  public:
  divisibleBy(int n): Functors(n){}
  bool operator()(int n) { return n%number ? false : true;  }


};

class greaterThan: public Functors {
  public:
  greaterThan(int num): Functors(num) {}
  bool operator()(int n) { return n < number ? false : true;  }

};

}