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
class King : public Piece
{
public:
	King(Color c) : Piece(c) {}

	std::stringstream draw();
};

