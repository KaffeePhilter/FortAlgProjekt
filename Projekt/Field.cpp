#include "Field.h"

Field::~Field()
{
}

std::stringstream Field::draw()
{
	std::stringstream draw;
	if (m_piece == nullptr)
		draw << "[ ]";
	else
		draw << "[" << m_piece.get()->draw().str() << "]";
	return draw;
}

std::string Field::toString()
{
	std::stringstream s;
	s << m_column << " | " << m_row;
	return s.str();
}
