#pragma once


#include<iostream>
#include<math.h>

class Drawable{
public:
	virtual void draw() const = 0;
	virtual double length() const = 0;
};

 void draw(Drawable *d){
	d->draw();
}
class Transformable{
public:
	virtual void shift(double x, double y) = 0;
};


class ClosedShape{
public:
	virtual double area() const = 0;
};

class Section;
class Deltoid;
class Circle;

class Point: public Transformable{
public:
friend class Section;
friend class Circle;
friend std::ostream & operator<<(std::ostream& o, const Point& k);
Point(double x, double y):_f(x), _s(y){}
void shift(double x,double y){
  _f += x;
  _s +=y;
}
protected:
double _f;
double _s;

};

class Circle:public Drawable, public ClosedShape, public Transformable{
public:
Circle(Point x, double y):_sro(x), _pro(y){}
void shift(double x,double y){
  _sro.shift(x,y);
}

void draw() const {
  std::cout << "Rysujemy kolo o srodku " << _sro << " i promieniu " << _pro<< std::endl;
}

double length() const{
  return 2 * M_PI * _pro;
}

double area() const override{
		return M_PI * std::pow(_pro, 2.0);
	}

protected:
Point _sro;
double _pro;

};

class Section:public Drawable, public Transformable{
public:
friend Deltoid;
Section(Point x, Point y):_first(x),_second(y){
  _length = std::sqrt(std::pow(_second._f-_first._f,2.0)+std::pow(_second._s-_first._s,2.0));
}
double length() const{
  return _length;
}
void shift(double x,double y){
  _first.shift(x,y);
  _second.shift(x,y);
}

void draw() const{
		std::cout << "Rysujemy odcinek od " << _first << " do " << _second << std::endl;
	}

protected:
Point _first;
Point _second;
double _length;


};

class Deltoid:public Drawable, public ClosedShape, public Transformable {
public:
Deltoid(Section x, Section y):_f_sec(x),_s_sec(y){}

Deltoid(Point x, Point y, Point z, Point l):_f_sec(Section(x,y)), _s_sec(Section(z,l)){}

void shift(double x,double y){
  _f_sec.shift(x,y);
  _s_sec.shift(x,y);
}

void draw() const{
		std::cout << "Rysujemy deltoid o wierzcholkach "<< _f_sec._first<<" "<<_f_sec._second <<" "<<_s_sec._first << " "<< _s_sec._second<< std::endl;
	}

	double length() const{
		return 2 * _f_sec.length() + 2 * _s_sec.length();
	}

double area() const override{
		return 0.5 * _f_sec.length() * _s_sec.length();
	}
protected:

Section _f_sec;
Section _s_sec;


};




std::ostream & operator<<(std::ostream& o, const Point& k){
 return  o<<"Punkt  ("<< k._f<<", "<<k._s<<")";
}
