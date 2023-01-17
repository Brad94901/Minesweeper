#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "BoardGenerator.h"

class GameLogic
{
	public:
		GameLogic();
		void newGame();						//return default 9x9 board
		void newGame(int width, int height); //return custom size board
		void newGame(int width, int height, int bombCount);
		void reveal(int x, int y);
		bool victorychecker(int x, int y);
		int scoreCount();
		Cell** board;						//The Game Board (recieves from BoardGenerator)
	private:
		BoardGenerator* gen;
		int numRevealedCells=0;
		int boardSize;
		int bombCount;
};

#endif