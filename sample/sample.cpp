#include "ls/SpinLock.h"
#include "thread"
#include "vector"
#include "iostream"

using namespace std;
using namespace ls;
// 多线程写数组

SpinLock lc(5);

vector<int> a;
void function1(int n)
{
	lc.lock();
	for(int i=0;i<5;++i)
	{
		a.push_back(i + n*5);
	}
	lc.unlock();
}
void test1()
{
	std::thread t[2];
	for(int i=0;i<2;++i)
		t[i] = thread(function1, i);

	for(int i=0;i<2;++i)
		t[i].join();

	for(int i=0;i<10;++i)
		cout << a[i] << endl;
}
// 多线程同步唤醒
void function2(int n)
{
	lc.wait();
	for(int i=0;i<100;++i)
		cout << n * 5 + i << endl;
}
void test2()
{
	thread t[2];
	for(int i=0;i<2;++i)
		t[i] = thread(function2, i);
	int c;
	cin >> c;
	if(c == 1)
		lc.unlock();
	for(int i=0;i<2;++i)
		t[i].join();
}

int main()
{
	test1();
	test2();
}
