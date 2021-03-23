#include "FilterCriteria.h"
  int FilterCriteria::size()const{
    return vec.size();
  }


  void FilterCriteria::add(const std::function<bool(int)>&fun){
      vec.push_back(fun);
  } 

  std::function<bool(int)>& FilterCriteria::get(int i){
    return vec[i];
  }