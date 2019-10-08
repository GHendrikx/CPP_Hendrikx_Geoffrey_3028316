#include "NPCDecorator.h"
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <time.h>

NPCDecorator::NPCDecorator(NPC* npc) : npc(npc)
{
}

NPCDecorator::~NPCDecorator()
{


}


//rendering
void NPCDecorator::render()
{
	npc->render();
}
