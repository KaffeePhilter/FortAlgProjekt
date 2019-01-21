#pragma once
#include "Field.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <map>

typedef std::map<int, Field*> BoardMap;

class Chessboard
{
public:
	Chessboard();
	~Chessboard();

	Field findKnight();
	Field findKing();
	void initialize(std::ifstream& file);
	std::stringstream draw();

	BoardMap* getBoard() { return &m_board; }

private:
	BoardMap m_board;
};

