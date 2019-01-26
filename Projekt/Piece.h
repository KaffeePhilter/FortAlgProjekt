/*
******Projekt to solve the knight problem********
*************************************************
Authors:	Philipp Horlaender & Konrad Muench
Course:		Computer Engineering
Semsester:	WiSe 2018/2019
**************************************************
*/

#pragma once
#include <sstream>
#include "Color.h"
class Piece
{
public:
	Piece(Color c) : m_color(c) {}
	virtual ~Piece();

	virtual Color getColor() { return m_color; }
	
	virtual std::stringstream draw() = 0;

private:
	Color m_color;
};

