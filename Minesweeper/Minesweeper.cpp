// Minesweeper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Game.h"


int main()
{
	Game game;

	while (true)
	{
		
		int x, y;

		std::cout << "--------------------------------------" << std::endl;
		std::cout << "x: ";
		std::cin >> y;

		std::cout << "y: ";
		std::cin >> x;

		if (x < 0 || y < 0)
			break;

		if (game.click(x, y))
		{
			std::cout << "Write something and click enter to exit!" << std::endl;
			std::cin >> x;
			std::cout << x;
			break;
		}
	}

    return 0;
}

