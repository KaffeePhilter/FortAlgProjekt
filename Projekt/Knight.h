/*
******Projekt to solve the knight problem********
*************************************************
Authors:	Philipp Horlaender & Konrad Muench
Course:		Computer Engineering
Semsester:	WiSe 2018/2019
**************************************************
*/

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

