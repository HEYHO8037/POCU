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
		void Enqueue(const T& number);
		T Dequeue();
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount();
		unsigned int GetStackCount();
	private:
		std::queue<std::stack<T>> mQueue;
		unsigned int mMaxStackSize;
		unsigned int mCount = 0;
	};


	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize), mCount(0)
	{
	}

	template<typename T>
	QueueStack<T>::QueueStack(const QueueStack& queueStack)
	{
		mQueue = queueStack.mQueue;
		mMaxStackSize = queueStack.mMaxStackSize;
		mCount = queueStack.mCount;
		mSum = queueStack.mSum;
	}

	template<typename T>
	QueueStack<T>& QueueStack<T>::operator=(const QueueStack& queueStack)
	{
		if (&queueStack == this)
		{
			return *this;
		}

		mQueue = queueStack.mQueue;
		mMaxStackSize = queueStack.mMaxStackSize;
		mCount = queueStack.mCount;
		mSum = queueStack.mSum;

		return *this;
	}

	template<typename T>
	QueueStack<T>::~QueueStack()
	{
	}


	template<typename T>
	void QueueStack<T>::Enqueue(const T& number)
	{
		if (mCount % mMaxStackSize == 0)
		{
			std::stack<T> saveStack;
			saveStack.push(number);
			mQueue.push(saveStack);
			mSum += number;
			mCount++;
		}
		else
		{
			mQueue.back().push(number);
			mSum += number;
			mCount++;
		}
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		T saveNumber = mQueue.front().top();
		mQueue.front().pop();
		mSum -= saveNumber;
		mCount--;

		if (mQueue.front().size() == 0)
		{
			mQueue.pop();
		}

		if (mQueue.empty())
		{
			mSum = NULL;
			mCount = 0;
		}

		return saveNumber;
	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		return mQueue.front().top();
	}

	template<typename T>
	T QueueStack<T>::GetMax()
	{
		T max = std::numeric_limits<T>::lowest();
		std::queue<std::stack<T>> saveQueue = mQueue;

		while (!saveQueue.empty())
		{
			while (!saveQueue.front().empty())
			{
				if (saveQueue.front().top() >= max)
				{
					max = saveQueue.front().top();
					saveQueue.front().pop();
				}
				else
				{
					saveQueue.front().pop();
				}
			}

			saveQueue.pop();
		}

		return max;
	}

	template<typename T>
	T QueueStack<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();
		std::queue<std::stack<T>> saveQueue = mQueue;

		while (!saveQueue.empty())
		{
			while (!saveQueue.front().empty())
			{
				if (saveQueue.front().top() <= min)
				{
					min = saveQueue.front().top();
					saveQueue.front().pop();
				}
				else
				{
					saveQueue.front().pop();
				}
			}

			saveQueue.pop();
		}

		return min;
	}

	template<typename T>
	double QueueStack<T>::GetAverage()
	{
		double average = static_cast<double>(GetSum());
		average /= mCount;

		return average;
	}

	template<typename T>
	T QueueStack<T>::GetSum()
	{
		T sum = NULL;
		std::queue<std::stack<T>> saveQueue = mQueue;

		while (!saveQueue.empty())
		{
			while (!saveQueue.front().empty())
			{
				sum += saveQueue.front().top();
				saveQueue.front().pop();
			}

			saveQueue.pop();
		}

		return sum;
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