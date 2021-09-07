#pragma once 
#include<iostream>



class DivisibleBy{
public:
DivisibleBy(int x):_value(x){}
bool operator()(int y){
  if(y%_value==0) return 0;
  return 1;
}

protected:
int _value;


};


class GreaterThan{
public:
GreaterThan(int x):_value(x){}
bool operator()(int y){
  if(y>_value) return 0;
  return 1;
}

protected:
int _value;


};