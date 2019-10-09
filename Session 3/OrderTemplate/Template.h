#pragma once
#include <algorithm>

template <typename T>
class Template
{
public:
	Template();
	virtual ~Template();
	void sortingTArray(T objArray[], int n);
	void printArray(T objArray[], int n);
};

template<typename T>
inline Template<T>::Template()
{
}

template<typename T>
inline Template<T>::~Template()
{
}

template<typename T>
inline void Template<T>::sortingTArray(T objArray[], int n)
{	
	//Get the array size
	std::sort(objArray, objArray+n); //Use the start and end like this

	for (int y = 0; y < n; y++) {
		std::cout << objArray[y] << std::endl;
	}
	std::cout << std::endl;
}

template<typename T>
inline void Template<T>::printArray(T objArray[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << objArray[i] << std::endl;
	}
}
