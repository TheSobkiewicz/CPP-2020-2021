#pragma once
#include <iostream>


struct Policy {
  virtual std::string policyName() const = 0;//virtualna funkcja, odpowiedzialna za wypisywanie klas pochodnych
  virtual ~Policy() = default;
};


struct CachePolicy : public Policy {
    virtual void cacheValueForArgument( double arg, double val ) const  = 0; // zapamietuje warosc obliczenia dla argumentu
    virtual bool hasCacheFor( double arg ) const = 0;  // zwraca true jesli w cachu znajduje sie wartosc dla argumentu
    virtual double getCached(double arg) const = 0; // zapamietana wartosc dla argumentu
};


struct OneCallCache :  virtual CachePolicy {
    virtual void cacheValueForArgument( double arg, double val ) const  {// zapamietuje warosc obliczenia dla argumentu
      argument = arg;
      value = val;
    } 
     bool hasCacheFor( double arg ) const { // zwraca true jesli w cachu znajduje sie wartosc dla argumentu
      return argument==arg;
      }  
     double getCached(double arg) const {// zwracamy zapamietana wartosc dla argumentu

       return value;
     } 

    std::string policyName() const {// zwracamy nazwe polityki
      return "OneCallCache";
    }

   mutable double value=0;
   mutable double argument=0;
};


struct NoCache :  virtual CachePolicy {
     void cacheValueForArgument( double arg, double val ) const {} //funkcja nie ma efektu
     bool hasCacheFor( double arg ) const {// zwraca false, obiekt z tą politką nic nie zapamietuje
       return false;
       }  
     double getCached( double arg ) const {
        return 0; 
        }// implementacja występuje tylko z powodu zdefiniowania tej funckji jako virtual w base class
      std::string policyName() const { // funkcja zwraca nazwe
      return "NoCache";
    }
};


struct VerbosityPolicy : public Policy {
    virtual void printArgAndResult( double arg, double val) const = 0;// wypisuje na stdout argument i wynik dzialania na tym argumencie
}; 



struct Verbose :  virtual VerbosityPolicy {
  void printArgAndResult( double arg, double val) const {//wypisujemy argument i wynik dzialania
      std::cout << "f(" << arg << ") = " << val << std::endl;
  }

   std::string policyName() const {// zwracamy nazwe polityki

      return "Verbose";
    } 
} ;

struct Silent :  virtual VerbosityPolicy {
  void printArgAndResult( double arg, double val) const {}//funkcja nie ma efektu

   std::string policyName() const {
      return "Silent";
    }// zwracamy nazwe polityki

} ;