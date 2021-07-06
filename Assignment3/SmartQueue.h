#pragma once
#include <queue>

#pragma once


namespace assignment3
{
	template<typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		SmartQueue(const SmartQueue& smartQueue);
		SmartQueue& operator=(const SmartQueue& smartQueue);
		void Enqueue(T number);
		T Dequeue();
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();
	private:
		std::queue<T> mQueue;
		unsigned int mCount = 0;
	};

	template<typename T>
	SmartQueue<T>::SmartQueue()
		: mCount(0)
	{
	}

	template<typename T>
	SmartQueue<T>::SmartQueue(const SmartQueue& smartQueue)
	{
		mCount = smartQueue.mCount;

		for (unsigned int length = 0; length < mCount; length++)
		{
			mQueue.push(smartQueue.mQueue[length]);
		}
	}

	template<typename T>
	SmartQueue<T>& SmartQueue<T>::operator=(const SmartQueue& smartQueue)
	{
		if (mQueue.size() != 0)
		{
			for (unsigned int length = 0; length < mCount; length++)
			{
				mQueue.pop();
			}
		}

		mCount = smartQueue.mCount;

		for (unsigned int length = 0; length < mCount; length++)
		{
			mQueue.push(smartQueue.mQueue[length]);
		}
	}


	template<typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		mQueue.push(number);
		mCount++;
	}

	template<typename T>
	T SmartQueue<T>::Dequeue()
	{
		T saveTemplate = mQueue.front();
		mQueue.pop();
		mCount--;

		return saveTemplate;
	}

	template<typename T>
	T SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}


	template<typename T>
	T SmartQueue<T>::GetMax()
	{
		T max = std::numeric_limits<T>::min();

		if (mCount == 0)
		{
			return max;
		}
		else
		{
			for (unsigned int length = 0; length < mCount; length++)
			{
				if (max < mQueue[length])
				{
					max = mQueue[length];
				}
				else
				{
					continue;
				}
			}

			return max;
		}
	}


	template<typename T>
	T SmartQueue<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();

		if (mCount == 0)
		{
			return min;
		}
		else
		{
			for (unsigned int length = 0; length < mCount; length++)
			{
				if (min > mQueue[length])
				{
					min = mQueue[length];
				}
				else
				{
					continue;
				}
			}

			return min;
		}
	}

	template<typename T>
	double SmartQueue<T>::GetAverage()
	{
		double average = 0;

		for (unsigned int length = 0; length < mCount; length++)
		{
			average += mQueue[length];
		}

		average /= mCount;

		return average;
	}

	template<typename T>
	T SmartQueue<T>::GetSum()
	{
		T total = 0;

		for (unsigned int length = 0; length < mCount; length++)
		{
			total += mQueue[length];
		}

		return total;
	}

	template<typename T>
	double SmartQueue<T>::GetVariance()
	{
		double average = GetAverage();
		double singleVariance;
		double totalVariance;

		for (unsigned int length = 0; length < mCount; length++)
		{
			singleVariance = average - mQueue[length];
			singleVariance *= singleVariance;
			totalVariance += singleVariance;
		}

		totalVariance /= mCount;

		return totalVariance;
	}

	template<typename T>
	double SmartQueue<T>::GetStandardDeviation()
	{
		double x = 2;
		unsigned int rotation = 10;
		double standardDeviation = GetVariance();

		for (unsigned int length = 0; length < rotation; length++)
		{
			x = (2 + (standardDeviation / x)) / 2;
		}

		return x;
	}

	template<typename T>
	unsigned int  SmartQueue<T>::GetCount()
	{
		return mCount;
	}
}