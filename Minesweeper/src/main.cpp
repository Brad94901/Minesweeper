#include <iostream>
#include "GUI.h"
#include "GameLogic.h"
#include "cell.h"
#include <iostream>

void cell_main() {
	int score = 0;
	Cell* c = new Cell(true);
	if (c->getIsBomb()) {
		score += 1;

		if (c->getBombCount() == 0) {
			score += 1;
		}

		if (c->getStatus() == false) {
			score += 1;
		}
		c->activate();

		if (c->getStatus() == true) {
			score += 1;
		}

		c->setBombCount(6);

		if (c->getBombCount() == 6) {
			score += 1;
		}

		std::cout << score << " correct out of" << 5 << std::endl;
	}
}


int main()
{
	int playagain = 1;
	int x = 0;
	int height = 9;
	int width = 9;
	int bombs = 10;

	while (playagain == 1)
	{

			x = difficultymenu();

		while (x == 0)
		{

			helpmenu();
			x = difficultymenu();
		}

		if (x == 1)
		{
			height = 9;
			width = 9;
			bombs = 10;
		}
		else if (x == 2)
		{
			height = 15;
			width = 13;
			bombs = 40;
		}
		else if (x == 3)
		{
			height = 16;
			width = 30;
			bombs = 99;
		}
		else if (x == 4)
		{
			//LOAD GAME FUNCTION GOES HERE
		}


		//Create Window
		//buildwindow(12,12);
		cell_main();
		//Create game instance

		//write main loop that starts a new game on game over

		GameLogic* g = new GameLogic();
		g->newGame(height, width, bombs);


		playagain = buildwindow(g, height, width);
}
}