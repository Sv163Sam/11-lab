





#pragma once 
#include <iostream> 
#include <utility> 

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
    broken_line(const unsigned int size); 
    broken_line(const broken_line& rhs); 

    void swap(broken_line& rhs); 
    
    point& operator[](const unsigned int index); 
    point operator[](const unsigned int index) const; 
    broken_line& operator= (const broken_line& obj); 
    
    friend broken_line& operator+(const broken_line& line, const broken_line& line_s); 
    friend broken_line& operator+(const point& point, const broken_line& line); 
    friend broken_line& operator+(const broken_line& line, const point& point);    
    friend broken_line& operator+=(const broken_line& line, const broken_line& line_s); 
    friend broken_line& operator+=(const point& point, const broken_line& line); 
    friend broken_line& operator+=(const broken_line& line, const point& point);  

    std::istream& operator>>(broken_line& line); 
    std::ostream& operator<<(const broken_line& line); 
    std::istream& operator>>(point& point); 
    std::ostream& operator<<(const point& point);
    
    ~broken_line();    

    double len(const broken_line& line);
    int quantity();

    bool operator > (const broken_line& a);
    bool operator < (const broken_line& a);
    bool operator == (const broken_line& a);
};