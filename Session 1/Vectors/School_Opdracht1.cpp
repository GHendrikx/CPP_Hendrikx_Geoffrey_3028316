// School_Opdracht1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Student.h"
#include "Docent.h"
#include "Module.h"
#include <vector>

int main()
{
#pragma region Initializing


	//initiallize all the studentnames
	std::string studentNames[10] =
	{
		"Kayley Wilder",
		"Kiera Higgins",
		"Marley Donnelly",
		"Iona Vinson",
		"Shantelle Wyatt",
		"Arisha Santiago",
		"Pedro Crossley",
		"Osman Estes",
		"Keith Cresswell",
		"Fergus Pitt"
	};
	std::string docentNames[3] =
	{
	"Eppo",
	"Edwin",
	"Valentijn"
	};
	std::string moduleNames[3] =
	{
		"ECTTP",
		"Object Oriented Programming Basic",
		"Object Oriented Programming Advance"
	};

	//initialize the vector variable on the heap.
	auto* students = new std::vector<Student>();
	auto* modules = new std::vector<Module>();
	auto* teachers = new std::vector<Docent>();
	
	//Fill the vector variable
	for (int i = 0; i < 3; i++)
	{
		Docent temp = Docent(docentNames[i]);
		teachers->push_back(temp);
	}
	auto docentIterator = teachers->begin(); 
	
	for (int i = 0; i < 10; i++)
	{
		Student temp = Student(studentNames[i]);
		students->push_back(temp);
	}
	auto studentIterator = students->begin();
	
	
	//assigning students to the modules and creating the modules.
	for(int i = 0; i< 3; i++)
	{
		Module temp = Module(moduleNames[i], *docentIterator, std::rand() % 3 + 1);
		
		int counter = 0;
		while (counter < 3) 
		{
			temp.joinModule(*studentIterator);

			studentIterator++;
			counter++;
		}
		modules->push_back(temp);
		docentIterator++;
	}
#pragma endregion

	//Part 1 & 2
	auto modulesIterator = modules->begin();

	while (modulesIterator != modules->end())
	{
		modulesIterator->printModuleInfo();

		modulesIterator++;
	}

	system("pause");
	system("cls");

//part 3 
	modulesIterator = modules->begin();
	modulesIterator->ChangeECS();

	while (modulesIterator != modules->end())
	{
		modulesIterator->printModuleInfo();

		modulesIterator++;
	}

	system("pause");
	system("cls");
//part 4
	modulesIterator = modules->begin();
	modulesIterator->removeStudent();

	while (modulesIterator != modules->end())
	{
		modulesIterator->printModuleInfo();

		modulesIterator++;
	}

#pragma region cleaning up in the garbage collection

	delete modules;
	delete students;
	delete teachers;

	system("pause");

	return 0;
#pragma endregion
}
