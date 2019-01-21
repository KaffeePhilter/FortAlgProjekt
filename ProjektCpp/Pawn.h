#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn() : Piece() {}

	std::stringstream draw();
};

