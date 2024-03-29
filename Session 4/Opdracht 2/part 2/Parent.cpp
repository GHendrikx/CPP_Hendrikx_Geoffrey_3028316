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

	this->name = std::move(other.name);
	this->child.reset(new Child(*other.child));
	return *this;
}

Parent& Parent::operator=(Parent&& other) noexcept
{
	std::cout << "MOVEASSIGNMENT" << std::endl;
	// Self-assignment detection
	if (&other == this)
		return *this;

	//Transfer values
	name = other.name;
	other.name = "";

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Parent& parent) {
	os << "parent name: " << parent.name << "," << *parent.child;
	return os;
}
