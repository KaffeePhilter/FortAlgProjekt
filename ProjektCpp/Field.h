#pragma once
#include <sstream>
#include "Piece.h"

class Field
{
public:
	Field();
	~Field();

	std::stringstream draw();

	unsigned short getRow() { return m_row; }
	char getColumn() { return m_column; }
	Piece* getPiece() { return m_piece; }

	void setRow(unsigned short row) { m_row = row; }
	void setColumn(char col) { m_column = col; }
	void setPiece(Piece* rP) { m_piece = rP; }
private:
	unsigned short m_row;
	char m_column;

	Piece* m_piece;
};
