#include "Cell.h"
#include <iostream>

Cell::Cell(int x, int y, Cell_Status status) : x(x), y(y), status(status)
{}

Cell::~Cell()
{
}

//Draw the Cell
void Cell::Draw()
{
	switch (status)
	{
	case Cell_Filled:
		std::cout << "X";
		break;
	case Cell_Empty:
		std::cout << ".";
		break;
	default:
		break;
		
	}
		
}
