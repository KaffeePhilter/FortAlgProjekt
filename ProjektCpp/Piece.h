#pragma once
#include <sstream>
class Piece
{
public:
	Piece();
	virtual ~Piece();

	virtual std::stringstream draw() = 0;
};

