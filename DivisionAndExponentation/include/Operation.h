#pragma once
#include <string>
#include <iostream>
class Operation {
public:

  friend void operator >>= (const std::string, const Operation&);
	virtual void print()const{}
	virtual double eval()const {
  return 0;
}

};
