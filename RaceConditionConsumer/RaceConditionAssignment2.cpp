#include <queue>
#include <thread>
#include <mutex>
#include <iostream>
#include <conio.h>

int counter = 0;
bool done = false;
std::queue<int> goods;
std::mutex mutex;

void producer() {
	mutex.lock();
	for (int i = 0; i < 500; ++i) {
		goods.push(i);
		counter++;
	}
	done = true;
	mutex.unlock();
}

void consumer() {
	while (!done) {
		while (!goods.empty()) {
			goods.pop();
			counter--;
		}
	}
}

int main() {
	system("cls");
	std::thread producerThread(producer);
	std::thread consumerThread(consumer);

	producerThread.join();
	consumerThread.join();

	std::cout << "Net: " << counter << " " << goods.size() << " " << std::endl;
	
	return 0;
}