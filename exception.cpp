#include "exception.h"
#include "iostream"
#include "string"

exc::exc(const char* msg)
{
	strncpy(_message, msg, 70);
}

const char* exc::get_message()
{
	return _message;
}

void exc::print()
{
	std::cout << "exc: " << _message << std::endl;
}

invalid_number::invalid_number()
	: exc(" uncorrect number of variable ") {}

invalid_index::invalid_index()
	: exc(" uncorrect index of broke line points array ") {}

empty_array::empty_array()
	: exc(" empty array ") {}

equal_points::equal_points()
	: exc(" this point is equal to one of the points of this array ") {}

equal_lines::equal_lines()
	: exc(" the lines are completely equal ") {}

uncorrect_type::uncorrect_type()
	: exc(" the entered value - uncorrect ") {}


