
//Statis of cell
enum Cell_Status 
{ 
	Cell_Filled, 
	Cell_Empty
}; 

#pragma once
class Cell
{
	public:
		int x;
		int y;
		Cell_Status status;
		Cell(int x, int y,Cell_Status status);
		~Cell();
		void Draw();
};

