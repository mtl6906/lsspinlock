#include "ls/SpinLock.h"
#include "unistd.h"

namespace ls
{
	SpinLock::SpinLock(int timeout) : timeout(timeout), number(0)
	{
	
	}

	void SpinLock::lock()
	{
		int zero = 0;
		while(!number.compare_exchange_strong(zero, 1))
			usleep(timeout);
	}

	void SpinLock::unlock()
	{
		number.store(0);
	}

	void SpinLock::wait()
	{
		number++;;
		while(number.load() != 0)
			usleep(5);
	}
	int SpinLock::count()
	{
		return number.load();
	}
}
