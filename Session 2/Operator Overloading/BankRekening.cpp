#include "BankRekening.h"

BankRekening::BankRekening(std::string name, int money)
{
	this->name = name;
	this->money = money;
}

BankRekening::~BankRekening()
{
}

//Operator overloading
BankRekening BankRekening::operator+(Cheque cheque)
{
	//get the 2 values
	int value = cheque.getAmount() + getAmount();
	//making the new bankrekening
	BankRekening* bankRekening = new BankRekening(this->name, value);
	//returning it
	return *bankRekening;
}

//if you wanna add the money
void BankRekening::addMoney(int money)
{
	this->money += money;
}

//if you want to decrease the money
void BankRekening::decreaseMoney(int money)
{
	this->money -= money;
}

//Get the name of the bankrekening
std::string BankRekening::getName()
{
	return name;
}

//Get the bankrekening amount
int BankRekening::getAmount()
{
	return money;
}

std::ostream& operator << (std::ostream& stream, BankRekening bankRekening)
{
	stream << bankRekening.getName() << ": " << bankRekening.getAmount();
	return stream;

}
