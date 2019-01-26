/*
******Projekt to solve the knight problem********
*************************************************
Authors:	Philipp Horlaender & Konrad Muench
Course:		Computer Engineering
Semsester:	WiSe 2018/2019
**************************************************
*/

#include "Knight.h"

void Knight::move(Field target)
{
}

//sstream for draw knight
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
