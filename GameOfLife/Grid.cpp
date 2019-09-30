#include "Grid.h"
#include <iostream>
#include "Windows.h"

Grid::Grid() 
{
	firstGeneration();
}

Grid::~Grid() {}


void Grid::firstGeneration()
{	
	raster[1][0] = Cell_Filled;
	raster[2][1] = Cell_Filled;
	raster[2][2] = Cell_Filled;
	raster[1][2] = Cell_Filled;
	raster[0][2] = Cell_Filled;
	
	printGrid();
}

void Grid::printGrid() 
{
	system("cls");
	for (int i = 0; i < HORIZONTAL_SIZE; i++)
	{
		for (int j = 0; j < VERTICAL_SIZE; j++)
		{
			switch (raster[j][i])
			{
				case Cell_Filled:
					std::cout << "*";
					break;
				case Cell_Empty:
					std::cout << ".";
					break;
				default:
					std::cout << ".";
					break;
			}
		}
		std::cout << std::endl;
	}

	Sleep(1000);
	calculateNeighbors();
}

void Grid::calculateNeighbors()
{
	for (int x = 0; x < HORIZONTAL_SIZE; x++)
		for (int y = 0; y < VERTICAL_SIZE; y++)
			checkNeighbors(x, y);

	printGrid();
}

void Grid::checkNeighbors(int x, int y)
{
	int neighbors = 0;
	
	if (raster[y + 1][x] == Cell_Filled) //rechts
		neighbors++;
	if (raster[y - 1][x] == Cell_Filled) // links 
		neighbors++;
	if (raster[y + 1][x-1] == Cell_Filled)//rechts boven
		neighbors++;
	if (raster[y][x-1] == Cell_Filled) //midden boven
		neighbors++;
	if (raster[y-1][x-1] == Cell_Filled) // links boven
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
