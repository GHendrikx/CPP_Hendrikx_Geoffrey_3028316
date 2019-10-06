#include "RuleSet.h"
#include "Cell.h"
#include "Grid.h"

void checkNeighbors(int x, int y,int raster[VERTICAL_SIZE][HORIZONTAL_SIZE])
{
	int neighbors = 0;

	if (raster[y + 1][x] == Cell_Filled) //rechts
		neighbors++;
	if (raster[y - 1][x] == Cell_Filled) // links 
		neighbors++;
	if (raster[y + 1][x - 1] == Cell_Filled)//rechts boven
		neighbors++;
	if (raster[y][x - 1] == Cell_Filled) //midden boven
		neighbors++;
	if (raster[y - 1][x - 1] == Cell_Filled) // links boven
		neighbors++;
	if (raster[y + 1][x + 1] == Cell_Filled)//rechts Onder
		neighbors++;
	if (raster[y][x + 1] == Cell_Filled) //midden onder
		neighbors++;
	if (raster[y - 1][x + 1] == Cell_Filled) // links onder
		neighbors++;

	//raster[y][x] = (neighbors == 3 ||
		//(raster[y][x] == Cell_Filled && neighbors == 2)) ? Cell_Filled : Cell_Empty;


	if (neighbors == 3)
		raster[x][y] = Cell_Filled;
	if (neighbors < 2 || neighbors > 3)
		raster[x][y] = Cell_Empty;

}
