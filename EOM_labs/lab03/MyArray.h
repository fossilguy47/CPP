#pragma once


#include<iostream>
#include<algorithm>
#include<utility>

class MyArray{
  public:
  friend std::ostream & operator <<(std::ostream &o, const MyArray&k);
  MyArray(int x):_size(x){
    tab = new int [x];
    for(int i =0; i<_size;i++){
      tab[i]=0;
    }
  }
  MyArray(const MyArray &x){
    delete []tab;
    tab = new int [x._size];
    _size = x._size;
    for(int i=0; i<_size;i++){
      tab[i] = x.tab[i]; 
    }
  }
  int & operator [](const int x)const {
    return tab[x];
  }
  
  int size()const {
    return _size;
  }
  
  MyArray operator ++(int){
    MyArray tmp(_size);
    for(int i=0; i<_size;i++){
      tmp.tab[i] = tab[i]++; 
    }
    return tmp;
  }
  MyArray operator --(){
    MyArray tmp(_size);
     for(int i=0; i<_size;i++){
      tmp.tab[i] = --tab[i]; 
    }
    return tmp;
  }

  MyArray& operator +=(MyArray & x){
   
    if (next == nullptr){
        next = &x;
    } 
    else{
        *next += x;
    }
    return *this;
    
  }

  MyArray(MyArray && x){
    _size = x._size;
    tab = std::move(x.tab);
    next = std::move(x.next);
  }
  
   MyArray& operator+=(MyArray&& T){
   	int* temp = new int[ _size + T._size ];
   	for (int i = 0; i < _size; ++i)	temp[i] = tab[i];
   	for (int i = 0; i < T._size; ++i)	temp[_size + i] = T.tab[i];
   	_size = _size + T._size;
   	tab = temp;
    return *this;
  }

  void print(std::string x){
    std::cout<< x;
    const MyArray* temp = this;
    while (temp->next != nullptr){
      std::cout<<*temp<<" ";
      temp = temp->next;
    } 
    std::cout<<*temp<<" ";

  }
  
  
  MyArray& operator=(const MyArray & x){
    if(this ==&x) return *this;
    delete []tab;
    tab = new int[x._size];
    _size = x._size;
    for(int i = 0;i<_size;i++){
      tab[i]=x.tab[i];
    }
      return *this;
  }
  MyArray& getNext(){
    return *next;
  }
  
  ~MyArray(){
    	delete [] tab; 
  }
  


  private:

  int * tab = nullptr;
  int _size;
  MyArray* next= nullptr;
};


std::ostream & operator <<(std::ostream &o, const MyArray&k){
  o<<"[";
  for(int i =0;i<k._size-1;i++){
    o<<k.tab[i]<<", ";
  }
  o<<k.tab[k._size-1]<<"]";
  
  return o;
}
