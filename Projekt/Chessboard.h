/*
******Projekt to solve the knight problem********
*************************************************
Authors:	Philipp Horlaender & Konrad Muench
Course:		Computer Engineering
Semsester:	WiSe 2018/2019
**************************************************
*/

#pragma once
#include "Field.h"
#include "Knight.h"
#include "King.h"
#include "Pawn.h"
#include "Color.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <memory>

typedef std::map<int, Field*> BoardMap;
typedef std::vector<std::vector<Field*>> BoardVector;

class Chessboard
{
public:
	Chessboard() {}
	~Chessboard() {}

	Field* findKnight();
	Field* findKing();
	
	void initialize(std::ifstream& file);
	std::stringstream draw();

	BoardMap* getBoardMap() { return &m_boardMap; }
	BoardVector* getBoardVector();

private:
	BoardMap m_boardMap;

	int getPos(char posX, int posY);
};

