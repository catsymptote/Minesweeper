#include "stdafx.h"
#include "Board.h"


Board::Board(int bombs, int x, int y)
{
	// Set size of baord.
	this->dimX = x;
	this->dimY = y;

	// Generate empty board.
	for (int i = 0; i < x; i++)
	{
		std::vector<Cell> tmpVector;
		for (int j = 0; j < y; j++)
		{
			Cell tmpCell(false);
			tmpVector.push_back(tmpCell);
		}
		board.push_back(tmpVector);
	}

	// Populate boards with bombs.
	this->populate(bombs);
}

Board::~Board() {}


void Board::print()
{
	std::cout << "\n\t";
	for (int i = 0; i < board.size(); i++)
		std::cout << i << "\t";
	std::cout << "\n\n";

	for (int i = 0; i < board.size(); i++)
	{
		std::cout << i << "\t";
		for (int j = 0; j < board.at(0).size(); j++)
		{
			if (board.at(i).at(j).isTriggered())
				if (board.at(i).at(j).isBomb())
					std::cout << "B";
				else
					std::cout << this->bombCount(i, j);
			else
			{
				std::cout << "X";
			}
			std::cout << "\t";
		}
		std::cout << "\n\n";
	}
	std::cout << "\n";
}

bool Board::triggerCell(int x, int y)
{
	if (this->board.at(x).at(y).trigger())
		return true;

	if (this->bombCount(x, y) == 0)
		this->autoTrigger(x, y);

	return false;
}

void Board::autoTrigger(int x, int y)
{
	// Cells around (x,y).
	int highX = this->dimX - 1;
	int highY = this->dimY - 1;
	int lowX = 0;
	int lowY = 0;

/*	Should not check for 0s diagonally.
	// --
	if (legal(x - 1, y - 1))
	{
		if(!this->board.at(x - 1).at(y - 1).isTriggered())
			this->triggerCell(x - 1, y - 1);
	}
		
	// +-
	if (legal(x -+ 1, y - 1))
	{
		if (!this->board.at(x + 1).at(y - 1).isTriggered())
			this->triggerCell(x + 1, y - 1);
	}
		
	// ++
	if (legal(x + 1, y + 1))
	{
		if (!this->board.at(x + 1).at(y + 1).isTriggered())
			this->triggerCell(x + 1, y + 1);
	}
	// -+
	if (legal(x - 1, y + 1))
	{
		if (!this->board.at(x - 1).at(y + 1).isTriggered())
			this->triggerCell(x - 1, y + 1);
	}
*/

	// 0-
	if (legal(x, y - 1))
	{
		if (!this->board.at(x).at(y - 1).isTriggered())
			this->triggerCell(x, y - 1);
	}
	// 0+
	if (legal(x, y + 1))
	{
		if (!this->board.at(x).at(y + 1).isTriggered())
			this->triggerCell(x, y + 1);
	}
	// -0
	if (legal(x - 1, y))
	{
		if (!this->board.at(x - 1).at(y).isTriggered())
			this->triggerCell(x - 1, y);
	}
	// +0
	if (legal(x + 1, y))
	{
		if (!this->board.at(x + 1).at(y).isTriggered())
			this->triggerCell(x + 1, y);
	}
}

void Board::triggerAll()
{
	for (int i = 0; i < dimX; i++)
	{
		for (int j = 0; j < dimY; j++)
		{
			board.at(i).at(j).trigger();
		}
	}
}

int Board::bombCount(int x, int y)
{
	// Count bombs around (x,y).
	int highX = this->dimX - 1;
	int highY = this->dimY - 1;
	int lowX = 0;
	int lowY = 0;

	int bombs = 0;

	// --
	if (legal(x - 1, y - 1)		&& this->board.at(x-1).at(y-1).isBomb())
		bombs++;
	// +-
	if (legal(x + 1, y - 1)		&& this->board.at(x + 1).at(y - 1).isBomb())
		bombs++;
	// ++
	if (legal(x + 1, y + 1)		&& this->board.at(x + 1).at(y + 1).isBomb())
		bombs++;
	// -+
	if (legal(x - 1, y + 1)		&& this->board.at(x - 1).at(y + 1).isBomb())
		bombs++;

	// 0-
	if (legal(x, y - 1)			&& this->board.at(x).at(y - 1).isBomb())
		bombs++;
	// 0+
	if (legal(x, y + 1)			&& this->board.at(x).at(y + 1).isBomb())
		bombs++;
	// -0
	if (legal(x - 1, y)			&& this->board.at(x - 1).at(y).isBomb())
		bombs++;
	// +0
	if (legal(x + 1, y)			&& this->board.at(x + 1).at(y).isBomb())
		bombs++;

	return bombs;
}

void Board::populate(int amount)
{
	srand((unsigned)time(0));
	//std::cout << (int)(rand() % 6) + 1;
	if (amount > dimX * dimY)
		amount = dimX * dimY;

	while (amount > 0)
	{
		// Get random coordinates.
		int x = rand() % this->dimX;
		int y = rand() % this->dimY;

		// If empty, place bomb.
		if (!this->board.at(x).at(y).isBomb())
		{
			this->board.at(x).at(y).setBomb();
			amount--;
		}
	}
}

bool Board::legal(int x, int y)
{
	if (x < 0)
		return false;
	if (y < 0)
		return false;
	if (x > dimX - 1)
		return false;
	if (y > dimY - 1)
		return false;
	
	return true;
}
