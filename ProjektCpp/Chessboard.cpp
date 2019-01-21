#include "Chessboard.h"
#include "Knight.h"
#include "King.h"
#include "Pawn.h"

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
		int pos = 0;

		switch (nextChar)
		{
		case 's':
			switch (file.get())
			{
			case 'a':
				pos += file.get();
				m_board[pos] = new Field();
				Knight* k();
				m_board[pos]->setPiece(k);
				break;
			case 'b':
				pos += 8 + file.get();
				break;
			case 'c':
				pos += 16 + file.get();
				break;
			case 'd':
				pos += 24 + file.get();

				break;
			case 'e':
				pos += 32 + file.get();

				break;
			case 'f':
				pos += 40 + file.get();

				break;
			case 'g':
				pos += 48 + file.get();

				break;
			case 'h':
				pos += 56 + file.get();

				break;
			}
			break;
		case 'b':
			break;
		case 'k':
			break;
		case 'S':
			break;
		case 'B':
			break;
		case 'K':
			break;
		case ',':
			continue;
		}
	}
}

std::stringstream Chessboard::draw()
{
	return std::stringstream();
}
