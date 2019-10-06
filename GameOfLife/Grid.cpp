#include "Grid.h"
#include <iostream>
#include "Windows.h"

Grid::Grid(RuleSet ruleSet) 
{
	this->ruleSet = ruleSet;
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
			ruleSet.checkNeighbors(x, y,raster);

	printGrid();
}
