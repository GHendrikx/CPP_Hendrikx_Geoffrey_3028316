// Templates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Template.h"

int main()
{
	//Making float Template
	Template<float> floatTemplate;
	float floatArray[] = {0,6,2,4,7,2,9};
	//setting size
	int size = std::size(floatArray);
	//sort
	floatTemplate.sortingTArray(floatArray, size);

	Template<std::string> stringTemplate;
	std::string stringArray[] = {"B","A","A","C"};
	size = std::size(stringArray);
	stringTemplate.sortingTArray(stringArray, size);
	
}