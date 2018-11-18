#pragma once

#include "Board.h"


class Game
{
public:
	Game(int bombs = 10, int x = 8, int y = 8);
	~Game();

	bool click(int x, int y);

private:
	Board grid;
	
};

