#pragma once
#include "Field.h"
#include <sstream>
#include <iostream>
#include <fstream>

class Chessboard
{
public:
	Chessboard();
	~Chessboard();

	Field findKnight();
	Field findKing();
	void initialize(std::ifstream& file);
	std::stringstream draw();
};

