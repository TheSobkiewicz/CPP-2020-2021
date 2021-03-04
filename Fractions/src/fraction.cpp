#include "fraction.h"
int nwd(int m, int n){
	int oldm, oldn;
	while( m % n != 0 ){
		oldm = m;
		oldn = n;
		m = oldn;
		n = oldm % oldn;
	}
	return n;
}

void simplify(int &l, int &m){
  int NWD=nwd(l,m);
  l=l/NWD;
  m=m/NWD;
  if(m<0){
    m=-m;
    l=-l;
  }
}

std::ostream& operator<<(std::ostream& strm, const Fraction &K)
{
    if(K._m!=0&&K._m!=1)
	return (strm << K._l << "/" << K._m);
    else{
        return (strm << K._l );
    }
}

Fraction Fraction::operator+(const Fraction &a){
  return Fraction(_l*a._m+_m*a._l,_m*a._m);
}

bool Fraction::operator >(Fraction dummy){
        double x1=_l/_m;
        double x2=dummy._l/dummy._m;
        if(x1>x2){
            return true;
        }
        else {
            return false;
        }

    }

Fraction Fraction::operator*(const Fraction &a)const{
  return Fraction(_l*a._l,_m*a._m);
}

int Fraction::operator[](int i){
        if (i==0){
            return _l;
        }
        else{
            return _m;
        }
  }

void Fraction::operator+=(const int a){
  int l=_l+a*_m,m=_m;
  simplify(l,m);
  _l=l;
  _m=m;
}

Fraction operator*(int i,const Fraction &a){
  return Fraction(a._l*i,a._m);
}



Fraction::Fraction(const Fraction &other):_l(other._l),_m(other._m){}

Fraction::Fraction(Fraction &&other):_l(other._l),_m(other._m){
    
    other._l=0;
    other._m=1;

}

Fraction &Fraction::operator=(const Fraction dummy){
       if (&dummy == this)
      return *this;
    _l=dummy._l;
    _m=dummy._m;

    return *this;
  }

  Fraction Fraction::operator-(){
    return Fraction(-_l,_m);
  }