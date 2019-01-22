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
