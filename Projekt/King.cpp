/*
******Projekt to solve the knight problem********
*************************************************
Authors:	Philipp Horlaender & Konrad Muench
Course:		Computer Engineering
Semsester:	WiSe 2018/2019
**************************************************
*/

#include "King.h"

//sstream for draw king
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
