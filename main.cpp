#include "threadpool.h"
#include <iostream>

using namespace std;

int val = 0;

int main()
{
	ThreadPool* pool = new ThreadPool(5, 10);
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "a");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "b");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "c");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "d");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "e");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "f");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "g");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "h");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "i");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "j");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "k");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "l");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "m");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "n");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "o");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "p");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "q");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "r");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "s");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "t");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "u");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "v");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "w");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "x");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "y");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "z");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "1");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "2");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "3");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "4");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "5");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "6");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "7");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "8");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "9");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "A");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "B");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "C");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "D");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "E");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "F");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "G");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "H");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "I");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "J");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "K");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "L");
	pool->pushTask([](const char* str) {cout << str << endl; std::this_thread::sleep_for(std::chrono::seconds(rand() % 5)); }, "M");
	while (1);
	delete pool;
	return 0;
}