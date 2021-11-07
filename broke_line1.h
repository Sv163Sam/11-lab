#pragma once 
#include <iostream> 
#include <utility> 
#include "exception.cpp"

template<typename A>
struct point 
{ 
  A _x, _y; 
  point<double>()
  {
    _x=0.0;_y=0.0;
  }
  point<double>(A x, A y)
  {
    _x=x;
    _y=y;
  }
}; 

template<typename T>
class broken_line 
{ 
private: 
    point<T>* _p; 
    unsigned _size; 
public: 
    /*broken_line(); 
    broken_line(point<T> var, const unsigned int size); 
    broken_line(const broken_line<T>& rhs);     
    point<T>& operator[](const unsigned int index); 
    point<T> operator[](const unsigned int index) const; 
    broken_line& operator= (const broken_line<T>& obj); 
    
    bool insert_point(const point<T>& point, bool value);

    broken_line operator+(const broken_line<T>& line_s) const; 
    broken_line operator+(const point<T>& point) const;    
    
    broken_line& operator+=(const broken_line<T>& line_s);  
    broken_line& operator+=(const point<T>& point);   
    
    ~broken_line();    

    double len(const broken_line<T>& line);
    //int quantity() const;

    bool operator > (const broken_line<T>& a);
    bool operator < (const broken_line<T>& a);
    bool operator == (const broken_line<T>& a);*/



    broken_line(): _p(NULL), _size(0) {} 

    broken_line<double>(point<T>& var, const unsigned int size) 
    { 
       _size = size; 
       _p = new point<T>[_size]; 
       for (int i = 0; i < _size; i++) 
       {
           _p[i]._x = var._x;
           _p[i]._y = var._y;
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

    broken_line(const broken_line<T>& line) 
    { 
       _size = line._size; 
       _p = new point<T>[_size]; 
       for (unsigned int i = 0; i < _size; i++)
        { 
           _p[i] = line._p[i]; 
        } 
    } 

    point<T>& operator[](const unsigned int index) 
    { 
       if (_size <= index || index < 0) throw invalid_index();
       return _p[index]; 
    } 

    point<T> operator[](const unsigned int index) const 
    { 
       if (_size <= index || index < 0) throw invalid_index();
       return _p[index]; 
    } 
    broken_line<T>& operator= (const broken_line<T>& obj)
    {
        if (_size <= 0) throw invalid_index();
        this->_size = obj._size;
        for (unsigned int i = 0; i < obj._size; i++) 
        {
            this->_p[i] = obj._p[i]; 
        }
        return *this;
    }

    int quantity() const
    {
        if (_size <= 0) throw invalid_index();
        return _size;
    }

    bool insert_point(const point<T>& p, bool value)
    {
        for (int i = 0; i < _size; i++)
        {
           if (p._x == _p[i]._x && p._y == _p[i]._y) throw equal_points();
        }
        point<T>* temp = new point<T>[_size];
        for (unsigned int i = 0; i < _size; i++) 
        {
            temp[i] = _p[i];
        }
        _p = new point<T>[_size + 1]; 
        _size++;
        if (value == true)
        {
            for (unsigned int i = 0; i < _size-1; i++) 
            {
                _p[i+1] = temp[i];
            }
            _p[0]._x = p._x;
            _p[0]._y = p._y;
        }
        else 
        {
            for (unsigned int i = 0; i < _size; i++) 
            {
                _p[i+1] = temp[i];
            }
            _p[_size-1]._x = p._x;
            _p[_size-1]._y = p._y;
        }
        delete[] temp;
    }

    broken_line<T>& operator+=(const point<T>& point) 
    {
        int value = 0;
        std::cout << "Please enter 0 - if you want to insert a point to start, 1 - if to end" << std::endl;
        std::cin >> value;
        if (value == 0)
        insert_point(point, true);
        else insert_point(point, false);
        return *this;
    }
    broken_line<T> operator+(const point<T>& point) const
    {
        broken_line<T> clone(*this);
        clone += point;
        return clone;
    }
    broken_line<T>& operator+=(const broken_line<T>& line_s)
    {
        if (*this == line_s) throw equal_lines();
        for (int i = 0; i < line_s._size; i++)
        {
            insert_point(line_s._p[i], false);
        }
        return *this;
    }
    broken_line<T> operator+(const broken_line<T>& line_s) const
    {
        broken_line<T> clone(*this);
        clone += line_s;
        return clone;
    }

    ~broken_line() 
    { 
       delete[] _p; 
    } 

    double len(const broken_line<T>& line)
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

    bool operator > (const broken_line<T>& a)
        {
            if (len(*this) <= len(a))
            {
                return false;
            }
            else return true;
        }
    bool operator < (const broken_line<T>& a)
        {
            if (len(*this) >= len(a))
            {
                return false;
            }
            else return true;
        }
    bool operator == (const broken_line<T>& a)
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

};