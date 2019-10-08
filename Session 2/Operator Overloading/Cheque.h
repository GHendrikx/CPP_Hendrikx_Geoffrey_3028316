#pragma once
class Cheque
{
public:
	Cheque(int amount);
	~Cheque();
	int getAmount();
private:
	int amount;
};

