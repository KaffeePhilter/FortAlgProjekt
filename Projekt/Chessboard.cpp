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
		int pos = 0;

		//lambda function as a variable for some counting stuff
		auto getPos = [&]()
		{
			// interpreting the chess board as a sequence of fields,
			// for each consecutive letter we add 8 to the count of the 
			// next char in the file, which should be a number from 1 to 8.
			// as a result we should get an index from 1-64 for each field, 
			// from left to right from top to bottom.
			switch (file.get())
			{
			case 'a':
				pos += file.get();
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
			return pos;
		};

		//checks for the next char and executes different stuff 
		switch (nextChar)
		{
		case 's':
			// s for knight, dont ask
			Knight* k();
			// Im broken, FIX plx
			m_board[getPos()]->setPiece(k);
			break;
		case 'b':
			// b for pawn, dont ask
			break;
		case 'k':
			// k for king, yey!
			break;
		case 'S':
			// capital S for black knight, dont ask
			break;
		case 'B':
			// capital B for black pawn, dont ask
			break;
		case 'K':
			// capital K for black king, dont ask
			break;
		case ',':
			// komma is a seperator
			continue;
		}
	}
}

std::stringstream Chessboard::draw()
{
	return std::stringstream();
}
