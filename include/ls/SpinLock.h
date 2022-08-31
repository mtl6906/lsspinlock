#ifndef LS_SPINLOCK_H
#define LS_SPINLOCK_H

#include "atomic"

namespace ls
{
	class SpinLock
	{
		public:
			SpinLock(int timeout);
			void lock();
			void unlock();
			void wait();
			int count();
		protected:
			std::atomic<int> number;
			int timeout;
	};
}

#endif
