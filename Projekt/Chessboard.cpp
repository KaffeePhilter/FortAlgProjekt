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
	//lambda function as a variable for some counting stuff
	auto getPos = [&file]()
	{
		// interpreting the chess board as a sequence of fields,
		// for each consecutive letter we add 8 to the count of the 
		// next char in the file, which should be a number from 1 to 8.
		// as a result we should get an index from 1-64 for each field, 
		// from left to right from top to bottom.

		char posX = file.get();
		int posY = file.get() - '0';
		int pos = 0;

		switch (posX)
		{
		case 'a':
			pos += posY;
			break;
		case 'b':
			pos += 8 + posY;
			break;
		case 'c':
			pos += 16 + posY;
			break;
		case 'd':
			pos += 24 + posY;

			break;
		case 'e':
			pos += 32 + posY;

			break;
		case 'f':
			pos += 40 + posY;

			break;
		case 'g':
			pos += 48 + posY;

			break;
		case 'h':
			pos += 56 + posY;

			break;
		}
		return pos;
	};

	while (file.peek() != file.eof())
	{
		char nextChar = file.get();
		int pos = 0;

		

		//checks for the next char and executes different stuff 
		switch (nextChar)
		{
		// s for knight, dont ask
		case 's':
		{
			std::shared_ptr<Piece> knight_(new Knight(Color::White));
			m_board[getPos()]->setPiece(knight_);
			break;
		}
		// b for pawn, dont ask
		case 'b':
		{
			std::shared_ptr<Piece> pawn_(new Pawn(Color::White));
			m_board[getPos()]->setPiece(pawn_);
			break;
		}
		// k for king, yey!
		case 'k':
		{
			std::shared_ptr<Piece> king_(new King(Color::White));
			m_board[getPos()]->setPiece(king_);
			break;
		}
		// capital S for black knight, dont ask
		case 'S':
		{
			std::shared_ptr<Piece> knight_(new Knight(Color::Black));
			m_board[getPos()]->setPiece(knight_);
			break;
		}
		// capital B for black pawn, dont ask
		case 'B':
		{
			std::shared_ptr<Piece> pawn_(new Pawn(Color::Black));
			m_board[getPos()]->setPiece(pawn_);
			break;
		}
		// capital K for black king, dont ask
		case 'K':
		{
			std::shared_ptr<Piece> king_(new King(Color::Black));
			m_board[getPos()]->setPiece(king_);
			break;
		}
		// komma is a seperator
		case ',':
		{
			continue;
		}
		}
	}
}

std::stringstream Chessboard::draw()
{
	return std::stringstream();
}
