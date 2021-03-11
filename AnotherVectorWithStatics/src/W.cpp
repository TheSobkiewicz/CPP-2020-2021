#include "W.h"

 W::W(int x){
	vals= new double[x];
	size=x;
	for(int i = 0; i<x; i++){
		vals[i]=0;
	}
}

double& W::at(int x)const{
	return vals[x];
}

double W::norm()const{
	double sum=0;
	for (int i = 0; i < size; i++){
		sum+= vals[i] * vals[i];
	}
	return sqrt(sum);
}

double W::dot(const W& w1,const W& w2){
	if (w1.size != w2.size){
		std::cout<<"Error, vectors of different dimensions!\n";
		return 0;
	}
	double sum=0;
	for (int i = 0; i< w1.size;i++){
		sum += w1.vals[i] * w2.vals[i];
	}
	return sum;
}


W::~W(){
	if(size!=0){
		size=0;
		delete[] vals;
	}
}

void W::print(std::string data)const{
std::cout<<data<<"[";
for(int i =0;i <size-1;i++)std::cout<<vals[i]<<", ";
std::cout<<vals[size-1]<<"]\n";
}


W W::operator+=(const W &w2){
  if (size != w2.size){
		return *this;
	}
  for(int i=0;i<size;i++){
    vals[i]+=w2.vals[i];
  }
return *this;
}
W W::operator+=(int add){
  for(int i=0;i<size;i++){
    vals[i]+=add;
  }
return *this;
}

W::W(const W& other):size(other.size){
	 vals = new double [size];
   
	for(int i = 0; i < size; i++){
		vals[i]=other.vals[i];
	}
}
W::operator double()const{
  return norm();
}

W::W( W&& other): size(std::exchange(other.size,0)),vals(std::exchange(other.vals,nullptr)){
}