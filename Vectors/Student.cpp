#include "Student.h"

Student::Student(std::string name) : name(name)
{
	int randomECS = (int)rand() % 30 + 1;
	Student::ec = randomECS;
}

std::string Student::getName() const
{
	return this->name;
}

int Student::getECS()
{
	return Student::ec;
}

void Student::addECS(int amount) {
	this->ec += amount;
}
