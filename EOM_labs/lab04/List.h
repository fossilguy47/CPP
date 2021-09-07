#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<functional>



class List{
public:
void insert(int x){
  _l.push_back(x);
}
void print(std::string x="")const {
  std::cout<<x<<"[ ";
  for(unsigned i =0;i<_l.size()-1;i++){
    std::cout<<_l[i]<<", ";
  }
  std::cout<<_l[_l.size()-1]<<"]"<<std::endl;

}
int& operator [](unsigned i){
  return _l[i];
}
List filter(std::function<bool(int x)> fun){
  List tmp;
  for(auto &i :_l){
    if(fun(i)){
      tmp.insert(i);
    }
  }
  return tmp;
}
protected:
std::vector<int> _l;

};