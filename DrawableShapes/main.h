#pragma once

#include "virtual.h"


class Point : public Transformable  {
	
  public:
	Point(double x, double y): wsp_x(x),wsp_y(y){}
	
	

  void shift(double x1, double y1) {
    wsp_x+=x1;
    wsp_y+=y1;
  }
	double getwsp_x() const{
		return wsp_x;
	}
	
	double getwsp_y() const{
		return wsp_y;
	}


	protected:
		double wsp_x;
		double wsp_y;
};

std::ostream& operator << (std::ostream& os,const Point& dummy){
		os<<"( "<<dummy.getwsp_x()<<","<<dummy.getwsp_y()<<")";
		return os;
	}
  
double Distance (const Point &a,const Point &b){
	return sqrt(pow(a.getwsp_x() - b.getwsp_x() , 2) + pow(a.getwsp_y() - b.getwsp_y() ,2));
};


class Circle : public Drawable, public ClosedShape, public Transformable{
  public:
	Circle (Point p,double radius):a(p),rad(radius){}

  void shift(double x1, double y1) {
    a.shift(x1,y1);
  }

  void print() const {
    std::cout <<"Rysujemy kolo o srodku" << a <<" i promieniu " << rad << std::endl;
  }
  
    double area() const {
    return rad*rad*M_PI;
  }
  double length () const {
    return 2 * rad * M_PI;
  }
  
	private:
		double rad;
  		Point a;
};


class Section: public Drawable, public Transformable{
	public:
		Section (Point q, Point p): a(q),b(p){}

    void shift (double x1 , double y1 ) {
      a.shift(x1,y1);
      b.shift(x1,y1);
    }

  void print() const {
    std::cout <<"Rysujemy odcinek od " << a <<" do " << b << std::endl;
  }

  double length() const{
		  return Distance (a,b);
  	}

	  Point getA() const{
		  return a;
	  }
	  Point getB() const{
		  return b;
	  }

	private:
		Point a;
		Point b; 
};



class Deltoid: public Drawable, public ClosedShape, public Transformable {
	public:

		Deltoid (Point a,Point b, Point c, Point d):ac(Section(a,c)) , bd(Section(b,d)) {}

		Deltoid (Section q, Section p): ac(q), bd(p){}
    
     void shift (double x1 , double y1 ) {
      ac.shift(x1,y1);
      bd.shift(x1,y1);
    }

	  void print() const {
        std::cout << "Rysujemy deltoid o wierzcholkach "<<ac.getA()<<","<<bd.getA()<<", "<<ac.getB()<<","<<bd.getB();
        std::cout<<std::endl;
  	}

     double area() const {
    return ac.length()*bd.length();
  }
	double length()const {
		return Distance(ac.getA(),bd.getA()) + Distance(bd.getA(),ac.getB()) + Distance(ac.getB(),bd.getB()) + Distance(bd.getB(),ac.getA());
	}


	private:
		Section ac;
		Section bd;

};

void draw(Drawable *toDraw) {
  toDraw->print();
};

