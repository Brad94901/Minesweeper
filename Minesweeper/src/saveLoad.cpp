#include "saveLoad.h"
#include <iostream>
#include <fstream>
#include "cell.h"
#include "BoardGenerator.h"

/*
void saveLoad::saveGame(Cell gameboard)
{
	int hight = gameboard.size();
	int width = gameboard[0].size();

	//ofstream out("save.txt");									//create variable to write to file
	//out.open();													//open file to 'save' the game to
	//out << hight << " " << width;								//write hight and width to the file

	for (int y = 0; y <= hight; y++)							//rows
	{
		for (int x = 0; x <= width; x++)						//column
		{
			bool isBomb = false;
			bool isRevealed = false;
			int adjacentMines = 0;									//could set to -1 to test to get "0" as an answer 

			isBomb = gameboard[y][x].getIsBomb();						//call function that returns if it is a bomb
			isRevealed = gameboard[y][x].getStatus();					//call function that returns if it has been revealed
			adjacentMines = gameboard[y][x].getBombCount();				//call function that returns number of adjacent bombs

			int bomb = 0; int revealed = 0;							//0 is false 1 is true

			if (isBomb) {											//if isBomb == True then change bomb = 1
				bomb = 1;
			}
			if (isRevealed) {										//if isRevealed == True then change revealed = 1
				revealed = 1;
			}

			//out << bomb << " " << revealed << " " << adjacentMines;
		}
		//out.close();												//close file
	}
}

void loadGame(){
	//ifstream in(save.txt);										//create variable to read from file
	//in.open();													//open saved game file
	int hight = 0; int width = 0;

	//in >> hight >> width;										//read in hight and width
	Cell** gameBoard = generateBoard(width, height);			//call function to generate a board with that hight/width

	for (int i = 0; i < hight; i++)								//rows
	{
		for (int j = 0; j < width; j++)							//column
		{
			int bomb = 0; int revealed = 0;						//0 is false 1 is true 
			int adjacentMines = 0;								//# of adjacent mines

			in >> bomb >> revealed >> adjacentMines;			//read in cell information isBomb, isRevealed, adjacentMines

			if (bomb == 1) gameBoard[i][j].setIsBomb();			//if bomb is == 1(true0 then set status = true
			if (revealed == 1) gameBoard[i][j].activate();		//if revealed is == 1(true) then set status = true
			setBombCount(gameboard[][], j, i, adjacentMines);	//set the number of adjacent mines
			//gameBoard[i][j].setBombCount(adjacentMines);		
		}
	}

	in.close();
}
*/