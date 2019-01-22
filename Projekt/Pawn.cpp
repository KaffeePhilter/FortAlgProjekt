#include "Pawn.h"

std::stringstream Pawn::draw()
{
	std::stringstream draw;
	if (getColor() == Color::Black)
		draw << "B";
	else if (getColor() == Color::White)
		draw << "b";
	else
		draw << " ";
	return draw;
}
