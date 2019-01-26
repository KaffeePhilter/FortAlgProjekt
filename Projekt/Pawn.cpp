/*
******Projekt to solve the knight problem********
*************************************************
Authors:	Philipp Horlaender & Konrad Muench
Course:		Computer Engineering
Semsester:	WiSe 2018/2019
**************************************************
*/

#include "Pawn.h"
// draw pawn
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
