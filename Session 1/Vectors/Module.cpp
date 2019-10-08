#include "Module.h"
#include <string>

std::vector<Student> students;


Module::Module(std::string moduleName, Docent docent, int ECS) : moduleName(moduleName),docent(docent),ECS(ECS)
{ }

void Module::joinModule(Student student)
{
	students.push_back(student);
}

void Module::changeECS() 
{
	this->ECS += 1;
}

void Module::removeStudent()
{
	auto iterator = students.begin();

	students.erase(iterator);
}

//Making the module print
void Module::printModuleInfo()
{
	int ecs = ECS;
	auto iterator = students.begin();
	std::string temp;
	temp += docent.getName();
	temp += "\n";
	temp += "ECS to earn \n";
	temp += std::to_string(ecs);
	temp += "\n";

	temp += "-------------------------\n";
	while (iterator != students.end()) 
	{
		temp += iterator->getName();
		temp += "\nstudent ECS: ";
		temp += std::to_string(iterator->getECS()) + "\n";
		temp += "student ECS + Module: " + std::to_string(iterator->getECS() + ecs);
		temp += "\n\n";
		iterator++;
	}
	std::cout << temp << std::endl;
	std::cout << std::endl;

}
