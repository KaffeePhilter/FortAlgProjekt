#include "Chessboard.h"

Chessboard::Chessboard()
{
}

Chessboard::~Chessboard()
{
}

Field Chessboard::findKnight()
{
	return Field();
}

Field Chessboard::findKing()
{
	return Field();
}

void Chessboard::initialize(std::ifstream& file)
{
	while (file.peek() != NULL)
	{
		char nextChar = file.get();
		int posX;
		int posY;

		if (nextChar == ',')
			continue;

		if (islower(nextChar))
		{
			switch (nextChar)
			{
			case 's':
				//TODO
				break;
			case 'b':
				//TODO
				break;
			case 'k':
				//TODO
				break;
			}
		}
	}
}

std::stringstream Chessboard::draw()
{
	return std::stringstream();
}
