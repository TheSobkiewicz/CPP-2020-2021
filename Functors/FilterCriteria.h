#pragma once
#include<functional>
#include<vector>

class FilterCriteria {
  public:

  int size()const;

  void add(const std::function<bool(int)> &fun );

  std::function<bool(int)>& get(int i);
  
  private:
  std::vector<std::function<bool(int)>> vec;
};