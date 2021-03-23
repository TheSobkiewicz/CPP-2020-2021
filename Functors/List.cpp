#include "List.h"
using namespace std;
void List::insert(int n ) {
  vec.push_back(n);
}

void List::print(std::string str)const {
  cout<<str<<" [ ";
  for (int n : vec)
    cout << n << " ";
  cout<<"]"<<endl;
}
int& List::operator[](int n){
  return vec.at(n);
}

List List::filter(function<bool(int)> fun)const{
  List filterList;
  for (int n : vec){
  if (fun(n))
    filterList.insert(n);
  }
  return filterList;
} 