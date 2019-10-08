#include <iostream>
#include "Student.h"
#include "Docent.h"
#include <vector>

#pragma once
class Module
{
public:
	Module(std::string moduleName,Docent docent, int ECS);
	void changeECS();
	void joinModule(Student student);
	void printModuleInfo();
	void removeStudent();
	int ECS;

private:
	std::vector<Student> students;
	Docent docent;
	std::string moduleName;
};

