#include <queue>
#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <chrono>

int counter = 0;
bool done = false;
std::queue<int> goods;
std::mutex mutexLock;
std::condition_variable cond;
std::unique_lock<std::mutex> locker(mutexLock);

void producer() {
	//locking the code - waiting on thread
	mutexLock.lock();
	for (int i = 0; i < 500; ++i) {
		goods.push(i);
		counter++;
	}
	cond.notify_one(); // wake up 1 sleeping thread
	mutexLock.unlock();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	done = true;
}

void consumer() {
	std::cout << "Wait Edwin" << std::endl;
	cond.wait(locker);
	std::cout << "Wait!!!! Edwin Wait!!!!!" << std::endl;
	while (!done) {
		while (!goods.empty()) {
			goods.pop();
			counter--;
		}
	}
	//unlocking code
	locker.unlock();
}

int main() {
	std::thread producerThread(producer);
	std::thread consumerThread(consumer);

	producerThread.join();
	consumerThread.join();

	std::cout << "Net: " << counter << " " << goods.size() << " " << std::endl;
}