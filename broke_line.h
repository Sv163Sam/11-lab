#pragma once 
#include <iostream> 
#include <utility> 

/* 
* Добавить: 
* -1- Перегрузка операторов сравнения (==, !=) 
*/ 

struct point 
{ 
  double _x, _y; 
  friend std::istream& operator>>(std::istream& in, point& lhs); 
  friend std::ostream& operator<<(std::ostream& out, const point& lhs); 

  point();
  point(double x, double y);
}; 

class broken_line 
{ 
private: 
    point* _p; 
    unsigned _size; 
public: 
    broken_line(); 
    broken_line(unsigned int size); 
    broken_line(const broken_line& rhs); 

    void swap(broken_line& rhs); 
    
    // по ссылке для записи данных, константый для чтения 
    point& operator[](unsigned int index); 
    point operator[](unsigned int index) const; 
    
    broken_line operator+(const broken_line& line); 
    broken_line operator+(const point& point); 
    broken_line operator+=(const point& rhs);
    
    friend std::istream& operator>>(std::istream& in, broken_line& line); 
    friend std::ostream& operator<<(std::ostream& out, const broken_line& line); 
    
    ~broken_line();    

    double len();
    
    bool operator > (broken_line& a);
    bool operator < (broken_line& a);
    bool operator == (broken_line& a);
};
