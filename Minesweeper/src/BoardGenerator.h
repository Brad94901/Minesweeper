#include "Cell.h"
class BoardGenerator
{
	public:
		BoardGenerator();
		Cell** generateBoard();
		Cell** generateBoard(int width, int height);
		Cell** generateBoard(int width, int height, int bombCount);
	private:
		Cell** board;
		void fillWithBombs(int bombsToAdd, int width, int height);
		
};