class FZlozona:public Op1{
  public:
    FZlozona(Fun* v){fun1=v;}
    double w(double x){return fun1->wartosc(fun->wartosc(x));}
    virtual Op1* z(Fun *x){fun=x;return this; }
  private:
  Fun *fun1;
};