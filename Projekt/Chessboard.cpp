#include "Chessboard.h"
#include "Knight.h"
#include "King.h"
#include "Pawn.h"


Field* Chessboard::findKnight()
{
	for (int i = 0; i < m_boardMap.size(); i++)
	{
		Piece* p = m_boardMap[i + 1]->getPiece().get();
		if (p != NULL)
		{
			std::string cmp = p->draw().str();
			if (cmp == "s" || cmp == "S")
				return m_boardMap[i + 1];
		}
	}
}

Field* Chessboard::findKing()
{
	for (int i = 0; i < m_boardMap.size(); i++)
	{
		Piece* p = m_boardMap[i + 1]->getPiece().get();
		if (p != NULL)
		{
			std::string cmp = p->draw().str();
			if (cmp == "k" || cmp == "K")
			{
				Field f = *m_boardMap[i+1];
				return m_boardMap[i + 1];
			}
		}
	}
}

void Chessboard::initialize(std::ifstream& file)
{
	short posY = 0;
	char posX;

	for (int i = 1; i <= 64; i++)
	{
		switch (i % 8)
		{
		case 1:
			posX = 'a';
			break;
		case 2:
			posX = 'b';
			break;
		case 3:
			posX = 'c';
			break;
		case 4:
			posX = 'd';
			break;
		case 5:
			posX = 'e';
			break;
		case 6:
			posX = 'f';
			break;
		case 7:
			posX = 'g';
			break;
		case 0:
			posY += 1;
			posX = 'h';
			break;
		}
		std::stringstream id;
		
		id << posX << posY;
		m_boardMap[i] = new Field(posX, posY, id.str());
	}

	while (!file.eof())
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
			char posX = file.get();
			char posY = file.get();
			
			pos = getPos(posX, posY - 48);
			m_boardMap[pos]->setPiece(knight_);
			break;
		}
		// b for pawn, dont ask
		case 'b':
		{
			std::shared_ptr<Piece> pawn_(new Pawn(Color::White)); 
			char posX = file.get();
			char posY = file.get();

			pos = getPos(posX, posY - 48);
			m_boardMap[pos]->setPiece(pawn_);
			break;
		}
		// k for king, yey!
		case 'k':
		{
			std::shared_ptr<Piece> king_(new King(Color::White));
			char posX = file.get();
			char posY = file.get();

			pos = getPos(posX, posY - 48);
			m_boardMap[pos]->setPiece(king_);
			break;
		}
		// capital S for black knight, dont ask
		case 'S':
		{
			std::shared_ptr<Piece> knight_(new Knight(Color::Black));
			char posX = file.get();
			char posY = file.get();

			pos = getPos(posX, posY - 48);
			m_boardMap[pos]->setPiece(knight_);
			break;
		}
		// capital B for black pawn, dont ask
		case 'B':
		{
			std::shared_ptr<Piece> pawn_(new Pawn(Color::Black));
			char posX = file.get();
			char posY = file.get();

			pos = getPos(posX, posY - 48);
			m_boardMap[pos]->setPiece(pawn_);
			break;
		}
		// capital K for black king, dont ask
		case 'K':
		{
			std::shared_ptr<Piece> king_(new King(Color::Black));
			char posX = file.get();
			char posY = file.get();

			pos = getPos(posX, posY - 48);
			m_boardMap[pos]->setPiece(king_);
			break;
		}
		// komma is a seperator
		case ',':
		{
			continue;
		}
		}
	}
	file.close();
}

std::stringstream Chessboard::draw()
{
	std::stringstream draw;
	for (int i = 0; i < m_boardMap.size(); i++)
	{
		draw << m_boardMap[i + 1]->draw().str();
		if ((i + 1) % 8 == 0)
			draw << std::endl;
	}
	return draw;
}

BoardVector * Chessboard::getBoardVector()
{
	int row = 0;
	int column = 0;
	BoardVector* boardVector = new BoardVector(8, std::vector<Field*>(8));

	for (int i = 1; i <= m_boardMap.size(); i++)
	{
		column = ((i-1) % 8);
		(*boardVector)[column][row] = m_boardMap[i];

		if (i % 8 == 0)
			row++;
	}
	return boardVector;
}

/* 
* interpreting the chess board as a sequence of fields,
* for each consecutive letter we add 8 to the count of the 
* next char in the file, which should be a number from 1 to 8.
* as a result we should get an index from 1-64 for each field, 
* from left to right from top to bottom.
*/
int Chessboard::getPos(char posX, int posY)
{
	int pos = 0;

	switch (posY)
	{
	case 1:
		pos += 0 + posX - 96;
		break;
	case 2:
		pos += 8 + posX - 96;
		break;
	case 3:
		pos += 16 + posX - 96;
		break;
	case 4:
		pos += 24 + posX - 96;
		break;
	case 5:
		pos += 32 + posX - 96;
		break;
	case 6:
		pos += 40 + posX - 96;
		break;
	case 7:
		pos += 48 + posX - 96;
		break;
	case 8:
		pos += 56 + posX - 96;
		break;
	}
	return pos;
}