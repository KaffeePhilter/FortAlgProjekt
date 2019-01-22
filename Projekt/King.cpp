#include "King.h"

std::stringstream King::draw()
{
	std::stringstream draw;
	if (getColor() == Color::Black)
		draw << "K";
	else if (getColor() == Color::White)
		draw << "k";
	else
		draw << " ";
	return draw;
}
