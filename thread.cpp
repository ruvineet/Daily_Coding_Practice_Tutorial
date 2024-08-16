#include <iostream>
#include <mutex>
#include <thread>
using namespace std;
mutex m;

void fun() {
	m.lock();
	cout << " thread print" << endl;
	m.unlock();
	}
int main() {
 thread t1(fun);
 thread t2(fun);
 t1.join();
 t2.join();
 return 0;
 }