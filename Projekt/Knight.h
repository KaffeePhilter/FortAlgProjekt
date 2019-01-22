#pragma once
#include "Piece.h"
#include "Field.h"

class Knight : public Piece
{
public:
	Knight() : Piece() {}

	void move(Field target);
	std::stringstream draw();
};

