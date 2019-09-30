#pragma once
#include "NPC.h"

class NPCDecorator : public NPC
{ 
private:
	NPC* npc;
public:
	NPCDecorator(NPC* npc);
	virtual ~NPCDecorator();
	void render();
};

