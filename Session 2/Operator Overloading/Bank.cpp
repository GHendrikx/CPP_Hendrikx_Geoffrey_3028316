// Bank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BankRekening.h"
#include "Cheque.h"

int main()
{
	std::string name = "";
	int amount = 0;

	std::cout << "What's your name" << std::endl;
	std::cin >> name;
	std::cout << "Whats the amount on your bank account" << std::endl << std::endl;
	std::cin >> amount;
	 
	BankRekening bankRekening = BankRekening(name, amount);
	
	int chequeAmount;
	std::cout << "What's the cheque amount you recieved? " << std::endl;
	std::cin >> chequeAmount;


	Cheque cheque = Cheque(chequeAmount);

	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Old Value = " << bankRekening << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	BankRekening newBankRekening = bankRekening + cheque;
	std::cout << "New Value = " << newBankRekening << std::endl;
	

}
