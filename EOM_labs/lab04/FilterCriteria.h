#pragma once

#include<iostream>
#include<functional>
#include<vector>

class FilterCriteria{
public:
void add(std::function<bool(int)> x){
  _criteria.push_back(x);
}
std::function<bool(int)> get(int x){
  return _criteria[x];
}
int size(){
  return _criteria.size();
}

protected:
  std::vector<std::function<bool(int)>> _criteria;


};