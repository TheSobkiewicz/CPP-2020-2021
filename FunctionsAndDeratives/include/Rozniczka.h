class ProstaRozniczka:public Op1{
  public:
    ProstaRozniczka(double v){h=v;}
    double w(double x){
      return(fun->wartosc(x+h)-fun->wartosc(x-h))/(2*h);
      }
    virtual Op1* z(Fun *x){fun=x;return this; }
  private:
  double h;
};