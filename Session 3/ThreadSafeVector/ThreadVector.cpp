// ThreadVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "ThreadSafeVector.h"

int total = 0;
std::mutex mutex;

//square function
void square(int x) {
	//waiting for the calculation till the previous one is out of this function
	std::lock_guard<std::mutex> guard(mutex);
	total += x * x;
}

//calculating function
void calculate() {
	std::vector<std::thread> threads;
	for (int i = 1; i <= 100; i++) {
		threads.push_back(std::thread(&square, i));
	}

	for (auto& thread : threads) {
		thread.join();
	}
	std::cout << "total = " << total << std::endl;
}

//main function
int main() {

	for (int i = 0; i < 2000; ++i) {
		total = 0;
		calculate();
	}

	return 0;
}