#include "NPC.h"
#include "Orc.h"

Orc::Orc()
{
}

Orc::~Orc()
{
}

void Orc::render()
{
	//spread the message
	std::cout << "Character: Orc "<<std::endl << "class: " << role[rand() % 3] << std::endl << std::endl;
}
