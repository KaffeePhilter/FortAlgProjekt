#pragma once
#include <sstream>
class Field
{
public:
	Field();
	~Field();

	std::stringstream draw();
private:
	unsigned short row;
	char column;
};

