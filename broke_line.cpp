#include "broke_line.h" 
#include "cmath"
#include "exception.cpp"


point::point()
    {
        _x=0;_y=0;
    }
point::point(double x, double y)
{
    _x=x;
    _y=y;
}

broken_line::broken_line(): _p(NULL), _size(0) {} 

broken_line::broken_line(unsigned int size) 
{ 
   _size = size; 
   _p = new point[_size]; 
   for (int i = 0; i < _size; i++) 
   {
       std::cout << "Please enter a value of x, y \n";
       std::cin >> _p[i]._x;
       std::cin >> _p[i]._y;
       if (i > 1)
       {
           for (int j = 0; j < i; j++)
           {
           if (_p[i]._x == _p[j]._x && _p[i]._y == _p[j]._y) throw equal_points();
           }
       }
       if (_p[i]._x == (-0)) _p[i]._x = 0;
       if (_p[i]._y == (-0)) _p[i]._y = 0;
   }
} 

broken_line::broken_line(const broken_line& line) 
{ 
   _size = line._size; 
   _p = new point[_size]; 
   for (unsigned int i = 0; i < _size; i++)
    { 
       _p[i] = line._p[i]; 
    } 
} 

void broken_line::swap(broken_line& rhs) 
{ 
   std::swap(_size, rhs._size); 
   std::swap(_p, rhs._p); 
} 

point& broken_line::operator[](unsigned int index) 
{ 
   if (_size <= index) throw invalid_index();
   return _p[index]; 
} 

point broken_line::operator[](unsigned int index) const 
{ 
   if (_size <= index) throw invalid_index();
   return _p[index]; 
} 

broken_line broken_line::operator+(const broken_line& rhs) 
{ 
    int count = 0; 
    for (unsigned int i = 0; i < _size; i++)
    {
        if (_p[i]._x == rhs._p[i]._x && _p[i]._y == rhs._p[i]._y) count++;
    }
    if (count == _size) throw equal_lines();

    
    if (_p[_size - 1]._x == rhs._p[0]._x && _p[_size - 1]._y == rhs._p[0]._y)
    {
        int clone_size = _size; 
        _size = _size + rhs._size - 1;
    for (unsigned int i = clone_size; i < _size - 1; i++)
    { 
        _p[i - 1] = rhs._p[i - clone_size - 1]; 
    } 
    return *this; 
    }
    int clone_size = _size; 
    _size = _size + rhs._size;
    for (unsigned int i = clone_size; i < _size; i++)
    { 
       _p[i] = rhs._p[i - clone_size]; 
    } 
    return *this; 
} 

broken_line broken_line::operator+(const point& rhs) 
{ 
   for (int i = 0; i < _size; i++)
   {
       if (rhs._x == _p[i]._x && rhs._y == _p[i]._y) throw equal_points();
   }
   _size = _size + 1;
   for (int i = _size; i > 0; i--)
   {
       _p[i] = _p[i - 1];
   }
   _p[0]._x = rhs._x;
   _p[0]._y = rhs._y;
   return *this; 
} 

broken_line broken_line::operator+=(const point& rhs) 
{ 
   for (int i = 0; i < _size; i++)
   {
       if (rhs._x == _p[i]._x && rhs._y == _p[i]._y) throw equal_points();
   }
   _size = _size + 1;
   _p[_size - 1]._x = rhs._x;
   _p[_size - 1]._y = rhs._y;
   return *this; 
} 

broken_line::~broken_line() 
{ 
   delete[] _p; 
} 

std::istream& operator>>(std::istream& in, point& lhs) 
{ 
   std::cout << "Input x: "; 
   in >> lhs._x; 
   std::cout << "Input y: "; 
   in >> lhs._y; 
   return in; 
} 

std::ostream& operator<<(std::ostream& out, const point& lhs) 
{ 
    out << "\nx - " << lhs._x; 
    out << "\ny - " << lhs._y; 
    return out; 
} 

std::istream& operator>>(std::istream& in, broken_line& lhs) 
{ 
    for (unsigned int i = 0; i < lhs._size; i++) { 
    in >> lhs._p[i]; 
    } 
    return in; 
} 

std::ostream& operator<<(std::ostream& out, const broken_line& lhs) 
{ 
   for (unsigned int i = 0; i < lhs._size; i++) { 
   out << i << " point is: "<< lhs._p[i]; 
   out << '\n'; 
   } 

return out; 
}

double broken_line:: len()
    {
        double sum=0;
        if (_size == 1)
        {
            return sum;
        }
        for (int i = 0; i < _size - 1; i++)
        {
            
            sum += sqrt(pow((_p[i + 1]._x - _p[i]._x), 2) + pow((_p[i + 1]._y - _p[i]._y), 2));
        }
        return sum;
    }

bool broken_line::operator > (broken_line& a)
    {
        if (len() <= a.len())
        {
            return false;
        }
        else return true;
    }
bool broken_line::operator < (broken_line& a)
    {
        if (len() >= a.len())
        {
            return false;
        }
        else return true;
    }
bool broken_line::operator == (broken_line& a)
    {
        if (len() < a.len() || len() > a.len())
        {
            return false;
        }
        else return true;
    }


