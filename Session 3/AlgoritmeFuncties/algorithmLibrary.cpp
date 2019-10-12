
#include <iostream>
#include <algorithm>
#include <vector>

//printing vector
void printVector(std::vector<std::string>* stringVector)
{
	std::cout << std::endl;
	auto iterator = stringVector->begin();

	while (iterator != stringVector->end()) {
		std::cout << *iterator << std::endl;
		iterator++;
	}
}

//compare 2 string in alphabetical order
bool compareFunction(std::string a, std::string b) {
	//comparing string a and string b
	return a < b;
}

//deleting double elements
void deletingDoubleElements(std::vector<std::string>* stringVector) {
	auto iterator = stringVector->begin();
	auto secondIterator = stringVector->begin();
	while (iterator != stringVector->end()) {
		while (secondIterator != stringVector->end())
		{
			if (*iterator == *secondIterator)
			{
				stringVector->erase(iterator);
			}
			secondIterator++;
		}
		iterator++;
	}
	std::cout << "deleted elements" << std::endl;
}

//setting all letters uppercase
void settingUppercaseLetter(std::vector<std::string>* stringVector) {
	for (auto& i : *stringVector)
		std::transform(i.begin(), i.end(), i.begin(), ::toupper);
}

int main() {
	std::vector<std::string>* colours;
	std::vector<std::string> coloursAlfabeticBeforePurple(9);
	std::vector<std::string> coloursEverythingElse(9);
	std::vector<std::string> colourVector = { "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
	colours = &colourVector;


	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
	// 2) alle elementen UPPERCASE te maken.
	// 3) alle dubbele te verwijderen
	int i = 0;
	auto iterator = colours->begin();
	while (iterator != colourVector.end()) {
		if(iterator++ != colourVector.end())
			break;
		bool temp = compareFunction(*iterator, *iterator++);

		if (temp) {
			
			coloursAlfabeticBeforePurple.push_back(colourVector[i]);
		}
		else {
			coloursEverythingElse.push_back(colourVector[i]);
		}
		iterator++;
		i++;
	}
	//setting everything in uppercase
	settingUppercaseLetter(&coloursAlfabeticBeforePurple);
	settingUppercaseLetter(&coloursEverythingElse);

	//deleting double elements
	deletingDoubleElements(&coloursAlfabeticBeforePurple);
	deletingDoubleElements(&coloursEverythingElse);

	//printing vector
	printVector(&coloursAlfabeticBeforePurple);
	printVector(&coloursEverythingElse);


	std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 1) alle negatieve elementen te verwijderen
	// 2) voor alle elementen te bepalen of ze even of oneven zijn
	// 3) de som, het gemiddelde, en het product van alle getallen te berekenen

	return 0;
}
