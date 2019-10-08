#include "Cheque.h"

Cheque::Cheque(int amount) 
{
	this->amount = amount;
}

Cheque::~Cheque()
{
}

int Cheque::getAmount()
{
	return this->amount;
}
