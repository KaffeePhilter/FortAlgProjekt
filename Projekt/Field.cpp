/*
******Projekt to solve the knight problem********
*************************************************
Authors:	Philipp Horlaender & Konrad Muench
Course:		Computer Engineering
Semsester:	WiSe 2018/2019
**************************************************
*/

#include "Field.h"

Field::~Field()
{

}

//shard_ptr for get piece
std::shared_ptr<Piece> Field::getPiece()
{
	if (m_piece.get() == nullptr)
		return nullptr;
	else 
		return m_piece;
}

//sstream for draw chessboard
std::stringstream Field::draw()
{
	std::stringstream draw;
	if (m_piece == nullptr)
		draw << "[ ]";
	else
		draw << "[" << m_piece.get()->draw().str() << "]";
	return draw;
}

//to string function for row column
std::string Field::toString()
{
	std::stringstream s;
	s << m_column << " | " << m_row;
	return s.str();
}
