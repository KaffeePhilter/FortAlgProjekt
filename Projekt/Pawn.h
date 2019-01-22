#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Color c) : Piece(c) {}

	std::stringstream draw();
};

