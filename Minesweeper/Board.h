#pragma once

#include <vector>
#include <iostream>
#include <ctime>

#include "Cell.h"

class Board
{
public:
	Board(int bombs = 10, int x=8, int y=8);
	~Board();

	void print();
	bool triggerCell(int x, int y);
	void autoTrigger(int x, int y);
	void triggerAll();
	
	int dimX;
	int dimY;

private:
	std::vector< std::vector<Cell> > board;

	int bombCount(int x, int y);
	void populate(int amount);
	bool legal(int x, int y);

};
