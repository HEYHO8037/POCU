#pragma once
#include <queue>
#include <stack>

#pragma once
namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		QueueStack(const QueueStack& queueStack);
		QueueStack& operator=(const QueueStack& queueStack);
		~QueueStack();
		void Enqueue(T number);
		T Dequeue();
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount();
		unsigned int GetStackCount();
	private:
		std::queue< std::stack<T>* > mQueue;
		std::stack<T>* mStack = nullptr;
		unsigned int mMaxStackSize;
		unsigned int mCount = 0;
	};


	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
	{
	}

	template<typename T>
	QueueStack<T>::QueueStack(const QueueStack& queueStack)
	{
		std::queue< std::stack<T>* > saveQueue = queueStack.mQueue;
		std::stack<T> saveStack;

		mCount = queueStack.mCount;
		mMaxStackSize = queueStack.mMaxStackSize;

		while (!saveQueue.empty())
		{
			mStack = saveQueue.front();
			saveStack = *mStack;

			mStack = new std::stack<T>(saveStack);
			mQueue.push(mStack);

			saveQueue.pop();
		}
	}

	template<typename T>
	QueueStack<T>& QueueStack<T>::operator=(const QueueStack& queueStack)
	{
		std::queue< std::stack<T>* > saveQueue = queueStack.mQueue;
		std::stack<T> saveStack;

		if (mQueue.size() != 0)
		{
			for (unsigned int length = 0; length < mQueue.size(); length++)
			{
				delete mQueue.front();
				mQueue.pop();
			}
		}

		mCount = queueStack.mCount;
		mMaxStackSize = queueStack.mMaxStackSize;

		while (! saveQueue.empty())
		{
			mStack = saveQueue.front();
			saveStack = *mStack;

			mStack = new std::stack<T>(saveStack);
			mQueue.push(mStack);

			saveQueue.pop();
		}

		return *this;
	}

	template<typename T>
	QueueStack<T>::~QueueStack()
	{
		for (unsigned int length = 0; length < mQueue.size(); length++)
		{
			delete mQueue.front();
			mQueue.pop();
		}
	}


	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		if (mStack == nullptr)
		{
			mStack = new std::stack<T>();
			mStack->push(number);
			mCount++;
			mQueue.push(mStack);
		}
		else
		{
			mStack->push(number);
			mCount++;

			if (mCount % mMaxStackSize == 0 && mCount != 0)
			{
				mStack = nullptr;
			}
		}
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		T saveNumber;

		std::stack<T>* saveStack;
		saveStack = mQueue.front();

		saveNumber = saveStack->top();

		saveStack->pop();
		mCount--;

		if (saveStack->size() == 0)
		{
			delete mQueue.front();
			mQueue.pop();
		}

		return saveNumber;
	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		std::stack<T>* saveStack;
		saveStack = mQueue.front();

		return saveStack->top();
	}

	template<typename T>
	T QueueStack<T>::GetMax()
	{
		T max = std::numeric_limits<T>::lowest();
		std::queue< std::stack<T>* > saveQueue = mQueue;
		std::stack<T> saveStack;


		if (mCount == 0)
		{
			return max;
		}
		else
		{
			while(!saveQueue.empty())
			{
				mStack = saveQueue.front();
				saveStack = *mStack;
	
				for (unsigned int innerLength = 0; innerLength < mStack->size(); innerLength++)
				{
					if (max < saveStack.top())
					{
						max = saveStack.top();
						saveStack.pop();
					}
					else
					{
						saveStack.pop();
					}
				}

				saveQueue.pop();
			}

			return max;
		}
	}

	template<typename T>
	T QueueStack<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();
		std::queue< std::stack<T>* > saveQueue = mQueue;
		std::stack<T> saveStack;

		if (mCount == 0)
		{
			return min;
		}
		else
		{
			while (!saveQueue.empty())
			{
				mStack = saveQueue.front();
				saveStack = *mStack;

				for (unsigned int innerLength = 0; innerLength < mStack->size(); innerLength++)
				{
					if (min > saveStack.top())
					{
						min = saveStack.top();
						saveStack.pop();
					}
					else
					{
						saveStack.pop();
					}
				}

				saveQueue.pop();
			}

			return min;
		}
	}

	template<typename T>
	double QueueStack<T>::GetAverage()
	{
		std::queue< std::stack<T>* > saveQueue = mQueue;
		std::stack<T> saveStack;
		double average = 0;

		while (!saveQueue.empty())
		{
			mStack = saveQueue.front();
			saveStack = *mStack;

			for (unsigned int innerLength = 0; innerLength < mStack->size(); innerLength++)
			{
				average += saveStack.top();
				saveStack.pop();
			}
			saveQueue.pop();
		}
		average /= mCount;

		return average;
	}

	template<typename T>
	T QueueStack<T>::GetSum()
	{
		std::queue< std::stack<T>* > saveQueue = mQueue;
		std::stack<T> saveStack;

		T total = 0;

		while (!saveQueue.empty())
		{
			mStack = saveQueue.front();
			saveStack = *mStack;

			for (unsigned int innerLength = 0; innerLength < mStack->size(); innerLength++)
			{
				total += saveStack.top();
				saveStack.pop();
			}
			saveQueue.pop();
		}

		return total;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount()
	{
		return mCount;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetStackCount()
	{
		return mQueue.size();
	}
}