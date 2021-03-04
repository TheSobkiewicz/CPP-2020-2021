#include "MyPoem.h"
MyPoem::~MyPoem(){
  delete []poem;
}

MyPoem::MyPoem(int x){
      poem=new MyLine[x];
    size=x;
}
void MyPoem::setLine(int x, MyLine data){
    poem[x]=data;
}

void MyPoem::print()const{
    for (int i=0;i<size;i++){
        convertAndPrint(poem[i]);
    }
}
MyPoem::MyPoem(const MyPoem &a){
 poem=new MyLine[a.size];
  size=a.size;
for(int i=0;i<size;i++)poem[i]=a.poem[i];
}

MyPoem::MyPoem(MyPoem &&a){
 poem=new MyLine[a.size];
  size=a.size;
for(int i=0;i<size;i++)poem[i]=a.poem[i];
a.size=0;
}