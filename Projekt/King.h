#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King(Color c) : Piece(c) {}

	std::stringstream draw();
};

