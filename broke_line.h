





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
    
    bool insert_point(const point& point, bool value);

    broken_line operator+(const broken_line& line_s) const; 
    broken_line operator+(const point& point) const;    
    
    broken_line& operator+=(const broken_line& line_s);  
    broken_line& operator+=(const point& point);   
    
    ~broken_line();    

    double len(const broken_line& line);
    int quantity() const;

    bool operator > (const broken_line& a);
    bool operator < (const broken_line& a);
    bool operator == (const broken_line& a);
};