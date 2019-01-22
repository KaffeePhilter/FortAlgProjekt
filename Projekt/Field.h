#pragma once
#include <sstream>
#include "Piece.h"
#include "Node.h"

class Field : public Node
{
public:
	Field(char column, unsigned short row) : m_row(row), m_column(column) {}
	~Field();

	unsigned short getRow() { return m_row; }
	char getColumn() { return m_column; }
	std::shared_ptr<Piece> getPiece() { return m_piece; }

	void setRow(unsigned short row) { m_row = row; }
	void setColumn(char col) { m_column = col; }
	void setPiece(const std::shared_ptr<Piece>& rP) { m_piece = rP; }

	std::stringstream draw();
	std::string toString();
private:
	unsigned short m_row;
	char m_column;

	std::shared_ptr<Piece> m_piece;
};

