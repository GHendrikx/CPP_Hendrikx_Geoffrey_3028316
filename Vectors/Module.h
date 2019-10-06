#include <iostream>
#include "Student.h"
#include "Docent.h"
#include <vector>

#pragma once
class Module
{
public:
	Module(std::string moduleName,Docent docent, int ECS);
	void ChangeECS();
	void joinModule(Student student);
	void printModuleInfo();
	void RemoveStudent();
	int ECS;

private:
	std::vector<Student> students;
	Docent docent;
	std::string moduleName;
};

