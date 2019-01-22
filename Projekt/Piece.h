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

