#include "cell.h"

Cell::Cell(bool isBomb){
this -> isBomb = isBomb;
this -> status = false; 
this -> bombCount = 0;
this -> flag = false;
}
Cell::Cell()
{
	this -> isBomb = false;
	this -> status = false; 
	this -> bombCount = 0;
    this -> flag = false;
}
    int Cell::getBombCount()
    {
        return this -> bombCount;
    }

    bool Cell::getStatus()
    {
        return this -> status;
    }

    void Cell::activate()
    {
        this -> status = true;
    }

    bool Cell::getIsBomb()
    {
		return isBomb;
    }

    void Cell::setBombCount(int bc)
    {
        bombCount = bc;
    }
	
	void Cell::setIsBomb()
	{
		isBomb=true;
	}

    void Cell::setFlagged()
    {
        flag=true;
    }

    void Cell::setUnFlagged()
    {
        flag = false;
    }

    bool Cell::getFlagged()
    {
        return flag;
    }