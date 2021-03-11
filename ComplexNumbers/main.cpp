/* 
Prosze napisac klase ComplexNumber, ktora reprezentuje liczbę zespoloną.
Metody post- i preinkrementacji zwiekszaja o 1 tylko czesc rzeczywista liczby zespolonej.

Iloczyn liczb zespolonych nalezy obliczyc korzystajac ze wzoru:
(A1 + i*A2)*(B1 + i*B2) = A1*B1 - A2*B2 + i*(A1*B2 + A2*B1)

Porownujac dwie liczby zespolone prosze porownac ich moduly, czyli
R = re*re + im*im.

UWAGA!!!
Po odkomentowaniu #DEFINE ERROR, powinien pojawic sie blad kompilacji dokladnie w tej linii. Brak blędu oznacza -2 punkty.

*/

#include "ComplexNumber.h"
#include <iostream>

//#define ERROR

int main ()
{
  using namespace std;

  const ComplexNumber Z1 (1., 11);
  const ComplexNumber Z2 (2, 22.);

  ComplexNumber Z3 = static_cast<ComplexNumber>(3); //im=0
  // #ifdef ERROR
  //   ComplexNumber Z3_ = 3.; 
  // #endif

  cout<<"Z1: "<<Z1<<"\nZ2: "<<Z2<<"\nZ3: "<<static_cast<double>(Z3)<<"\n";
  //Dodawanie
  cout << "\n*** Dodawanie ***\n";
  ComplexNumber S1 = Z1 + Z2,
               S2 = 1+ ComplexNumber(0,2);
  cout<<"S1: "<<S1<<"\nS2: "<<S2<<"\n";

  const ComplexNumber& S2Ref = S2 = S1 = Z1*Z2;
  cout<<"S1: "<<S1<<"\tS2: "<<S2<<"\tS2Ref: "<<S2Ref<<"\n";
  
  cout << "\n*** S2*=3 ***\n";
  S2 *= 3;
  cout<<"S1: "<<S1<<"\tS2: "<<S2<<"\tS2Ref: "<<S2Ref<<"\n";
  ComplexNumber S3 (ComplexNumber(2,-1) + Z1*Z2 - (S2++) + (++S1) );
  cout<<"S1: "<<S1<<"\tS2: "<<S2<<"\tS3: "<<S3<<"\n";

  cout << "\n*** Zwiekszamy RE: S3[RE]+=3 ***\n";
  S3[(Z1 > S3) ? 1 : 0] += 3; // równoznaczne z S3[0] += 3;
  cout<<"S3: "<<S3<<"\n";

  cout << "*** Zwiekszamy IM: S3[IM]+=5 ***\n";
  S3[(S3 > Z1) ? 1: 0] += 5; // równoznaczne z S3[1] += 5;
  cout<<"S3: "<<S3<<"\n";

  
  return 0;
}
/*
Z1: 1 + 11i
Z2: 2 + 22i
Z3: 3

*** Dodawanie ***
S1: 3 + 33i
S2: 1 + 2i
S1: -240 + 44i  S2: -240 + 44i  S2Ref: -240 + 44i

*** S2*=3 ***
S1: -240 + 44i  S2: -720 + 132i S2Ref: -720 + 132i
S1: -239 + 44i  S2: -719 + 132i S3: 243 + -45i

*** Zwiekszamy RE: S3[RE]+=3 ***
S3: 246 + -45i
*** Zwiekszamy IM: S3[IM]+=5 ***
S3: 246 + -40i
*/
