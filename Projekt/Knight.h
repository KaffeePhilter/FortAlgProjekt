#pragma once
#include "Piece.h"
#include "Field.h"

class Knight : public Piece
{
public:
	Knight();
	~Knight();

	void move(Field target);
};

