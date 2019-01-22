#pragma once
#include "Piece.h"
#include "Field.h"

class Knight : public Piece
{
public:
	Knight(Color c) : Piece(c) {}

	void move(Field target);

	std::stringstream draw();
};

