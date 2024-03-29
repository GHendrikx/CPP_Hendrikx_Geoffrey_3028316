#include <iostream>
#include "Parent.h"

Parent::Parent(std::string name) {
	this->name = name;
	std::string childName = "ChildOf" + name;
	this->child.reset(new Child(childName));
}

Parent::Parent(const Parent& other) {
	std::cout << "Parent cctor" << std::endl;
	this->name = other.name;
	this->child.reset(new Child(*other.child));
}

Parent::~Parent() {
	std::cout << "Parent dtor : " << this->name << std::endl;
	delete this->child.release();
}

Parent& Parent::operator=(const Parent& other) {
	std::cout << "Parent assignment" << std::endl;

	if (this == &other) return *this;

	this->name = other.name;
	this->child.reset(new Child(*other.child));
	return *this;
}

Parent& Parent::operator=(Parent&& other) noexcept
{
	std::cout << "MOVEASSIGNMENT" << std::endl;
	// Self-assignment detection
	if (&other == this)
		return *this;

	name = nullptr;
	// Transfer ownership of a.m_ptr to m_ptr
	name = other.name;
	other.name = nullptr; // we'll talk more about this line below

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Parent& parent) {
	os << "parent name: " << parent.name << "," << *parent.child;
	return os;
}
