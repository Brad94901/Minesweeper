#ifndef CELL_H
#define CELL_H

class Cell
{
    public:
    int getBombCount();
    bool getStatus();
    void activate();
    bool getIsBomb();
	void setIsBomb();
    void setFlagged();
    void setUnFlagged();
    bool getFlagged();
    Cell(bool isBomb);
	Cell();
    void setBombCount(int bc);
    
    private:
    int bombCount;
    bool status;
    bool isBomb;
    bool flag;
};
#endif