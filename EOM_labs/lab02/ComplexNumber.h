#pragma once

#include<iostream>

class ComplexNumber{
public:
friend ComplexNumber operator+ (int x,const ComplexNumber &k);
friend std::ostream & operator <<(std::ostream &o,const ComplexNumber& k);

ComplexNumber(double x, double y=0.0):re(x),im(y){}

explicit operator double() const{
  return re;
}

ComplexNumber operator +( const ComplexNumber &x) const{
  ComplexNumber tmp(0.0,0.0);
  tmp.re = re+x.re;
  tmp.im = im+x.im;
  return tmp;
}

ComplexNumber operator *(const ComplexNumber &x) const{
  ComplexNumber tmp(re*x.re - im*x.im, re*x.im + im*x.re);
  return tmp;
}

ComplexNumber& operator *=(int x){
  re = re*x;
  im = im*x;
  return *this;
}

ComplexNumber& operator++(){
  re++;
  return *this;
}

ComplexNumber operator++(int x){
  ComplexNumber tmp = *this;
  ++*this;
  return tmp;
}

ComplexNumber operator -(const ComplexNumber& x)const {
  ComplexNumber tmp(re- x.re, im - x.im);
  return tmp;
}

ComplexNumber(const ComplexNumber &x){
  im = x.im;
  re = x.re;
}
bool operator >(const ComplexNumber & k) const{
  return static_cast<double>(*this)>static_cast<double>(k)?true:false;
}
double& operator [](int x){
  return x==0?re:im;
}

private:
  double re;
  double im;
};


std::ostream & operator <<(std::ostream &o,const ComplexNumber& k){
  o<<k.re<<" + "<<k.im<<"i";
  return o;
}

ComplexNumber operator+ ( int x,const ComplexNumber &k){
  ComplexNumber tmp(k.re +x, k.im);
  return tmp;
}
