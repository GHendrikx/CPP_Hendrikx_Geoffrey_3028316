// QueueSemantiek.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include "QueueTemplate.h"

void addEnters(int howMuch) {
	for (int i = 0; i <= howMuch; i++)
		std::cout << std::endl;
}

int main()
{
	float floatArray[] = { 0.1f,0.2f,0.5f,0.3f,0.2f,0.3f,0.5f };
	int size = std::size(floatArray) - 1;
	QueueTemplate<float> queue = QueueTemplate<float>(floatArray,size);

	queue.printVector();
	queue.put(1.1f);
	addEnters(1);
	std::cout << queue.size();
	addEnters(1);
	queue.printVector();
	addEnters(1);
	std::cout << queue.get();
	addEnters(1);
	queue.printVector(); 
}