class Op1{
  public:
virtual double w(double x){return 0;};
virtual ~Op1(){}
virtual Op1* z(Fun *x){return nullptr;}
  protected:
 Fun* fun;
};