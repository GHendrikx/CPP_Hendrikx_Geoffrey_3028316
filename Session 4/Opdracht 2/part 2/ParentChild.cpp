// ParentChild.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Parent.h"

int main() {
	std::shared_ptr<Parent> p1Shared(new Parent("Parent 1"));// = std::make_shared<Parent>(new Parent("Parent1"));
	std::shared_ptr<Parent> p2Shared(p1Shared);
	
	Parent* p1 = new Parent("Parent 1 not shared");

	Parent* p2 = new Parent(*p1); // roept de copy constructor aan
	std::cout << "p2:" << *p2 << std::endl;

	Parent* p3 = new Parent("Parent3");
	std::cout << "p3:" << *p3 << std::endl;

	*p3 = *p1; // roept de assignment operator aan
	std::cout << "p1:" << *p3 << std::endl;

	std::cout << "p1:" << p1Shared.use_count() << " shared" << std::endl;
	p2Shared = nullptr;
	std::cout << "p1 " << p1Shared.use_count() << " shared"<< std::endl;
	p1Shared.reset();
	delete p1Shared.get();


	delete p1;
	delete p2;
	delete p3;

	return 0;
}