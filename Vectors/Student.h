#include <iostream>

#pragma once
class Student
{
public:
	Student(std::string name);
	void addECS(int amount);
	int getECS();
	std::string getName() const;

private:
	int ec;
	std::string name;
	
};

