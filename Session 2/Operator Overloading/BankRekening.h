#include <iostream>
#include "Cheque.h"
#pragma once
#include <iostream>
class BankRekening
{
public:
	BankRekening(std::string name, int startValue);
	~BankRekening();
	BankRekening operator+(Cheque cheque);

	void addMoney(int money);
	void decreaseMoney(int money);
	std::string getName();
	int getAmount();
	friend std::ostream& operator << (std::ostream& output, BankRekening bankRekening);

private:
	std::string name;
	int money;
};

