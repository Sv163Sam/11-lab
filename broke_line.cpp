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

broken_line::broken_line(const unsigned int size) 
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

point& broken_line::operator[](const unsigned int index) 
{ 
   if (_size <= index) throw invalid_index();
   return _p[index]; 
} 

point broken_line::operator[](const unsigned int index) const 
{ 
   if (_size <= index) throw invalid_index();
   return _p[index]; 
} 
broken_line& broken_line::operator= (const broken_line& obj)
{
    if (_size <= 0) throw invalid_index();
    this->_size = obj._size;
    for (unsigned int i = 0; i < obj._size; i++) 
    {
        this->_p[i] = obj._p[i]; 
    }
    return *this;
}

int broken_line::quantity()
{
    if (_size <= 0) throw invalid_index();
    return _size;
}

broken_line& operator+(const broken_line& line, const broken_line& line_s) 
{ 
    int count = 0; 
    for (unsigned int i = 0; i < line._size; i++)
    {
        if (line._p[i]._x == line_s._p[i]._x && line._p[i]._y == line_s._p[i]._y) count++;
    }
    if (count == line._size) throw equal_lines();

    if (line._p[line._size - 1]._x == line._p[0]._x && line._p[line._size - 1]._y == line_s._p[0]._y)
    {
        int clone_size = line._size; 
        int a = line._size + line_s._size - 1;
        broken_line line_(a);
        for (unsigned int i = 0; i < line._size; i++)
        {
            line_._p[i] = line._p[i];
        }
        for (unsigned int i = clone_size; i < a - 1; i++)
        { 
            line_._p[i - 1] = line_s._p[i - clone_size - 1]; 
        } 
        return line_; 
    }
    else
    {
    int clone_size = line._size; 
    int a = line._size + line_s._size;
    broken_line line_(a);
    for (unsigned int i = 0; i < line._size; i++)
    {
        line_._p[i] = line._p[i];
    }
    for (unsigned int i = clone_size; i < a; i++)
    { 
       line_._p[i] = line_s._p[i - clone_size]; 
    } 
    return line_; 
    }
} 

broken_line& operator+(const point& point,const broken_line& line) 
{ 
   for (int i = 0; i < line._size; i++)
   {
       if (point._x == line._p[i]._x && point._y == line._p[i]._y) throw equal_points();
   }
   int a = line._size + 1;
   broken_line line_(a);
   for (int i = a; i > 0; i--)
   {
       line_._p[i] = line._p[i - 1];
   }
   line_._p[0]._x = point._x;
   line_._p[0]._y = point._y;
   return line_; 
} 

broken_line& operator+(const broken_line& line, const point& point) 
{ 
   for (int i = 0; i < line._size; i++)
   {
       if (point._x == line._p[i]._x && point._y == line._p[i]._y) throw equal_points();
   }
   int a = line._size + 1;
   broken_line line_(a);
   line_._p[a - 1]._x = point._x;
   line_._p[a - 1]._y = point._y;
   return line_; 
} 
/*
broken_line& operator+=(const broken_line& line, const point& point) 
{
    return (line+point);
}
broken_line& operator+=(const broken_line& line, const broken_line& line_s) 
{
    return (line+line_s);
}
broken_line& operator+=(const point& point, const broken_line& line) 
{
    return (point+line);
}
*/
broken_line::~broken_line() 
{ 
   delete[] _p; 
} 
std::istream& broken_line::operator>>(point& lhs) 
{ 
   std::cout << "Input x: "; 
   std::cin >> lhs._x; 
   std::cout << "Input y: "; 
   std::cin >> lhs._y; 
   return std::cin; 
} 

std::ostream& broken_line::operator<<(const point& lhs) 
{ 
    std::cout << "\nx - " << lhs._x; 
    std::cout << "\ny - " << lhs._y; 
    return std::cout; 
} 

std::istream& broken_line::operator>>(broken_line& lhs) 
{ 
    for (unsigned int i = 0; i < lhs._size; i++) { 
    std::cin >> lhs._p[i]; 
    } 
    return std::cin; 
} 

std::ostream& broken_line::operator<<(const broken_line& lhs) 
{ 
   for (unsigned int i = 0; i < lhs._size; i++) { 
   std::cout << i << " point is: "<< lhs._p[i]; 
   std::cout << '\n'; 
   } 
   return std::cout; 
}

double broken_line::len(const broken_line& line)
    {
        double sum=0;
        if (line._size == 1)
        {
            return sum;
        }
        for (int i = 0; i < line._size - 1; i++)
        {
            
            sum += sqrt(pow((line._p[i + 1]._x - line._p[i]._x), 2) + pow((line._p[i + 1]._y - line._p[i]._y), 2));
        }
        return sum;
    }

bool broken_line::operator > (const broken_line& a)
    {
        if (len(*this) <= len(a))
        {
            return false;
        }
        else return true;
    }
bool broken_line::operator < (const broken_line& a)
    {
        if (len(*this) >= len(a))
        {
            return false;
        }
        else return true;
    }
bool broken_line::operator == (const broken_line& a)
    {
        if (len(*this) < len(a) || len(*this) > len(a))
        {
            return false;
        }
        else 
        {
            int count = 0;
            for (unsigned int i = 0; i < _size; i++)
            {
                if (_p[i]._x == a._p[i]._x && _p[i]._y == a._p[i]._y) count++;
            }
            if (count == _size) return true;
        } 
        return false;
    }
