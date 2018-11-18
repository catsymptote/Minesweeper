#include "stdafx.h"
#include "Game.h"


Game::Game(int bombs, int x, int y)
{
	this->grid = Board(bombs, x, y);
	this->grid.print();
}

Game::~Game() {}

bool Game::click(int x, int y)
{
	// Check if cell (x,y) is within board(ers).
	if (x < 0 || x > this->grid.dimX -1 || y < 0 || y > this->grid.dimY -1)
	{
		// Just round up/down to legal x or y instead?
		std::cout << "Not within board size." << std::endl;
		return false;
	}

	// Trigger cell, and check if bomb.
	if (this->grid.triggerCell(x, y))
	{
		std::cout << ">>> GAME OVER <<<" << std::endl;
		this->grid.triggerAll();
		this->grid.print();
		std::cout << ">>> GAME OVER <<<" << std::endl;
		return true;
	}

	this->grid.print();
	return false;
}
