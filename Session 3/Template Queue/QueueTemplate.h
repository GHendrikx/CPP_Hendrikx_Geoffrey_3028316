#pragma once
#include <queue>
#include <iostream>
#include <array>

template<typename T>
class QueueTemplate {
public:
	QueueTemplate(T arrayOfTypes[], int size);
	virtual ~QueueTemplate();
	void put(T obj);
	void printVector();
	T get();
	int size();
private:
	std::vector<T> vectorQueue;
	int sizeOfCollection;
};

template<typename T>
inline QueueTemplate<T>::QueueTemplate(T arrayOfTypes[],int size)
{
	QueueTemplate::sizeOfCollection = size;
	for (int i = 0; i <= size; i++)
		QueueTemplate::vectorQueue.push_back(arrayOfTypes[i]);
}

template<typename T>
inline QueueTemplate<T>::~QueueTemplate()
{
	
}


template<typename T>
inline void QueueTemplate<T>::put(T obj)
{
	QueueTemplate::vectorQueue.push_back(obj);
}

template<typename T>
inline void QueueTemplate<T>::printVector()
{
	auto iterator = QueueTemplate::vectorQueue.begin();
	while (iterator != QueueTemplate::vectorQueue.end())
	{
		std::cout << *iterator << std::endl;
		iterator++;
	}
}

template<typename T>
inline T QueueTemplate<T>::get()
{
	auto iterator = QueueTemplate::vectorQueue.begin();
	T element = *iterator;
	QueueTemplate::vectorQueue.erase(iterator);
	return element;
}

template<typename T>
inline int QueueTemplate<T>::size()
{
	int size = QueueTemplate::vectorQueue.size();
	return size;
}


