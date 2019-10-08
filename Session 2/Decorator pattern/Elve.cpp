#include "NPC.h"
#include "Elve.h"

Elve::Elve()
{
}

Elve::~Elve()
{
}

void Elve::render()
{
	//spread the message
	std::cout << "Character: Elve " << std::endl << "class: " << role[rand() % 3] << std::endl << std::endl;
}
