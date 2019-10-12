// DecoratorPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "NPCDecorator.h"
#include "NPC.h"
#include "Elve.h"
#include "Orc.h"
#include "time.h";

int main()
{
	//Create the decorator class then rendering the object.
	srand(time(NULL));
	//making a new decorator
	NPCDecorator* decorator = new NPCDecorator(new Elve()); //ps: i know i spelled elf wrong if you were curious :p
	decorator->render();

	decorator = new NPCDecorator(new Orc());
	decorator->render();

	//deleting the object
	delete decorator;
}