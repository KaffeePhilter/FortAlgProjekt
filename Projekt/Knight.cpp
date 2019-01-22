#include "Knight.h"

void Knight::move(Field target)
{
}

std::stringstream Knight::draw()
{
	std::stringstream draw;
	if (getColor() == Color::Black)
		draw << "S";
	else if (getColor() == Color::White)
		draw << "s";
	else
		draw << " ";
	return draw;
}
