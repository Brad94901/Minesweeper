#include "GameLogic.h"
#include <iostream>
GameLogic::GameLogic()
{
	gen = new BoardGenerator();
}

void GameLogic::newGame()
{
	//generate default board
	if(board != NULL)
	{
		delete[] board;
	}
	board = gen->generateBoard();
}

void GameLogic::newGame(int width, int height)
{
	//generate custom board
	if(board != NULL)
	{
		delete[] board;
	}
	int boardSize = width * height;
	bombCount = (width*height)/2;
	board = gen->generateBoard(width, height);
}

void GameLogic::newGame(int width, int height, int bombCount)
{
	//generate custom board
	if(board != NULL)
	{
		delete[] board;
	}
	boardSize = width * height;
	bombCount = bombCount;
	board = gen->generateBoard(width, height, bombCount);
}

void GameLogic::reveal(int x, int y)
{
	board[x][y].activate();
	numRevealedCells++;
}

bool GameLogic::victorychecker(int x, int y)
{
	//will positionselected be checked beforehand to make sure it is actually a usable cell
	//asumming cell is usable
	
	if(board[x][y].getIsBomb() == true || numRevealedCells == (boardSize - bombCount)) //if cell selected was bomb or all cells are revealed. 81 is placeholder for boardsize
	{
		return true;                         //return true, bomb was selected, game over. cell wont need status update
	}
	if(board[x][y].getIsBomb() == false) 
	{                          
		reveal(x,y);             //if cell selected was not bomb. update cell status to revealed
		return false;                         //return false, game has not ended
	}     
	
	return false;
}

int GameLogic::scoreCount() // will only run if victory checker returns true;
{
	int score = 0;
	for(int i = 0; i < 9; i++){ // 9 will be replaced with getheight()
		for(int j = 0; j < 9; j++){ // getwidth()
			if(board[i][j].getIsBomb() == true && board[i][j].getFlagged() == true)
				score++;
		}
	}	
					
	return score;
}