#include "BoardGenerator.h"
#include <iostream>
BoardGenerator::BoardGenerator()
{
}

Cell** BoardGenerator::generateBoard()//Returns a 9x9 Board by default
{
	board = new Cell*[9];
	for(int i=0; i<9 ;i++)
	{
		board[i] = new Cell[9];
	}
	fillWithBombs(9/2, 9, 9);
	return board;
}

Cell** BoardGenerator::generateBoard(int width, int height)//Return a width x height Board
{
	board = new Cell*[width];
	for(int i=0; i<width ;i++)
	{
		board[i] = new Cell[height];
	}
	fillWithBombs(width*height/2, width, height);
	return board;
}

Cell** BoardGenerator::generateBoard(int width, int height, int bombCount)//Return a width x height Board with (bombCount) bombs
{
	board = new Cell*[width];
	for(int i=0; i<width ;i++)
	{
		board[i] = new Cell[height];
	}
	fillWithBombs(bombCount, width, height);
	return board;
}

void BoardGenerator::fillWithBombs(int bombsToAdd, int width, int height)
{
	std::cout << width << " " << height << std::endl;
	int currentBombs = 0;
	
	//fill with bombs
	while(currentBombs < bombsToAdd)
	{
		for(int i=0; i<width; i++)
		{
			for(int j=0; j<height; j++)
			{
				if(rand()%10 > 5 && currentBombs < bombsToAdd)
				{
					board[i][j].setIsBomb();
					currentBombs++;
				}
			}
		}
	}
	
	//set bomb count in each cell
	bool inRange = false;
	for(int i=0; i<width; i++)
	{
		for(int j=0; j<height; j++)
		{
			board[i][j].setBombCount(0);//fake num
		}
	}
}
