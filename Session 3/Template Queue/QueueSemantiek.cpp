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


	queue.printQueue(); //printing queue
	queue.put(1.1f); //adding something to the queue
	addEnters(1); //just for readability
	std::cout << queue.size();
	addEnters(1); //just for readability
	queue.printQueue(); //printing queue
	addEnters(1); //just for readability
	std::cout << queue.get(); // getting first element
	addEnters(1); //just for readability
	queue.printQueue(); //printing queue
}