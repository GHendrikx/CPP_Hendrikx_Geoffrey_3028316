#pragma once
#include <iostream>

class NPC
{
public:
	NPC();
	~NPC();
	virtual void render() = 0;
	std::string role[3] =
	{
		" Farmer",
		" Soldier",
		" Shaman"
	};
};
