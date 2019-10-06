#pragma once
#include "Cell.h"
#include "RuleSet.h";

#define VERTICAL_SIZE 25
#define HORIZONTAL_SIZE 25

class Grid
{
	public:
		int raster[VERTICAL_SIZE][HORIZONTAL_SIZE];
		int rasterNeigh[VERTICAL_SIZE][HORIZONTAL_SIZE];
		void firstGeneration();
		void printGrid();
		void calculateNeighbors();
		Grid(RuleSet ruleSet);
		~Grid();
		Cell_Status status;
		void checkNeighbors(int x, int y);
		RuleSet ruleSet;
};

