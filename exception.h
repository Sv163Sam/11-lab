#pragma once

class exc
{
	char _message[70];
public:
	exc(const char* message);
	const char* get_message();
	virtual void print();
};
class invalid_number : public exc
{
public:
	invalid_number();
};
class invalid_index : public exc
{
public:
	invalid_index();
};
class empty_array : public exc
{
public:
	empty_array();
};
class equal_points : public exc
{
public:
	equal_points();
};
class equal_lines : public exc
{
public:
	equal_lines();
};
class uncorrect_type : public exc
{
public:
	uncorrect_type();
};

