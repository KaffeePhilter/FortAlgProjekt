#pragma once
#include <sstream>
#include "Piece.h"
#include "Node.h"

class Field : public Node
{
public:
	Field();
	~Field();

	unsigned short getRow() { return m_row; }
	char getColumn() { return m_column; }
	Piece* getPiece() { return m_piece; }

	void setRow(unsigned short row) { m_row = row; }
	void setColumn(char col) { m_column = col; }
	void setPiece(Piece* rP) { m_piece = rP; }

	std::stringstream draw();
private:
	unsigned short m_row;
	char m_column;

	Piece* m_piece;
};

