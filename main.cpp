#include "iostream"
#include "cmath"
#include "cstdlib"
#include "broke_line.cpp"
#include "string"

//Класс ломаных линий на плоскости с произвольным количеством вершин .
//Описать вспомогательную структуру в стиле Си для представления точек (вершин) на плоскости. Как минимум, предоставить:
//• конструктор с параметром: количество точек;
//• оператор [] для чтения/записи вершины ломаной по её индексу;
//• оператор сложения двух ломаных (конкатенация);
//• оператор сложения ломаной и вершины (добавление вершины в конец ломаной);
//• оператор сложения вершины и ломаной (вставка вершины в начало ломаной);
//• вычисление длины ломаной.

int get_key() 
{
    int key = getchar();
    if (key == 0 || key == 224)
        key = getchar();
    return key;
}

int menu()
{
    std::cout << "\nPress:\n1 - the sum of the lines,\n2 - the sum of the line and point at the end,\n"
    "3 - the sum of the line and point to start\n4 - accessing an point of the line by index\n"
    "5 - calсulate the length of the broken line\n6 - compare 2 lines\n"
    "Esc - terminate programm execution\n";
    while (true)
    {
        int key = get_key();
        if (key == 49 || key == 50 || key == 51 || key == 52 || key == 53 || key == 54|| key == 27)
            return key;
    }
}

void sum_lines(broken_line &obj){
    int second_line_p_amount = 0;       

    std::cout << "Please enter a value for the number of points to create a line \n";
    std::cin >> second_line_p_amount;
    if (second_line_p_amount < 0 || second_line_p_amount != int(second_line_p_amount) ||
    (second_line_p_amount < 0 && second_line_p_amount != int(second_line_p_amount))) throw invalid_number();

    broken_line second_line(second_line_p_amount);
    std::cout << second_line << '\n';
    obj + second_line;
}

void sum_line_and_point_to_end(broken_line &obj)
{
    double x = 0, y = 0;

    std::cout << "Enter point coordinates - INPUT ORDER: x -> Enter y -> Enter\n";
    std::cin >> x;
    std::cin >> y;
    obj += point(x, y);
}

void sum_line_and_point_to_start(broken_line &obj)
{
    double x = 0, y = 0;

    std::cout << "Enter point coordinates - INPUT ORDER: x -> Enter y -> Enter\n";
    std::cin >> x;
    std::cin >> y;
    obj + point(x, y);
}

int to_create_user_index()
{
    int index = 0;

    do {
    std::cout << "Enter index of point for search\n";
    std::cin >> index;
    if (index != int(index) || index < 0 || (index != int(index) && index < 0)) throw invalid_index();
    }while (index != int(index));
    return index;
}

int compare_lines (broken_line &obj, broken_line &sec_o)
{
    if (obj > sec_o) return 1;
    if (obj < sec_o) return 2;
    return 0;
}


int main()
{
    int first_line_p_amount = 0;        
    int select_var = 0;
    
    try 
    {
    std::cout << "Please enter a value for the number of points to create a line \n";
    std::cin >> first_line_p_amount;
    if (first_line_p_amount < 0 || first_line_p_amount != int(first_line_p_amount) ||
    (first_line_p_amount < 0 && first_line_p_amount != int(first_line_p_amount))) throw invalid_number();
    } catch (exc& err)
    {
	    err.print();
	    std::cin >> first_line_p_amount;
	}

    broken_line first_line(first_line_p_amount);
    std::cout << first_line << '\n';
    

    while (select_var != 1) 
    {
    try 
    {
    switch (menu())
    {
        case 49:
        {
            sum_lines(first_line);
            std::cout << first_line << '\n';
            break;
        }
        case 50:
        {
            sum_line_and_point_to_end(first_line);
            std::cout << first_line << '\n';
            break;
        }
        case 51:
        {
            sum_line_and_point_to_start(first_line);
            std::cout << first_line << '\n';
            break;
        }
        case 52:
        {
            std::cout << first_line[to_create_user_index()] << '\n';
            break;
        }
        case 53:
        {
            std::cout << first_line.len();
            break;
        }
        case 54:
        {
            int second_line_p_amount = 0;       
            std::cout << "Please enter a value for the number of points to create a line \n";
            std::cin >> second_line_p_amount;
            if (second_line_p_amount < 0 || second_line_p_amount != int(second_line_p_amount) ||
            (second_line_p_amount < 0 && second_line_p_amount != int(second_line_p_amount))) throw invalid_number();

            broken_line second_line(second_line_p_amount);

            if (compare_lines(first_line, second_line) == 0) 
            {
                std::cout << first_line;
                std::cout << "\n == \n";
                std::cout << second_line;
            }
            if (compare_lines(first_line, second_line) == 1) 
            {
                std::cout << first_line;
                std::cout << "\n > \n";
                std::cout << second_line;
            }
            if (compare_lines(first_line, second_line) == 2) 
            {
                std::cout << first_line;
                std::cout << "\n < \n";
                std::cout << second_line;
            }
            break;
        }
        case 27:{
            select_var = 1;
            break;
        }
        break;
    }
    }catch (exc& err)
    {
        err.print();
    }
    }
    std::cout << first_line << '\n';
    return 0;
}




