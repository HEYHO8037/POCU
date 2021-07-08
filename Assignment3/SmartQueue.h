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
		std::queue<T> mMaxQueue;
		std::queue<T> mMinQueue;
		std::queue<T> mSumQueue;
		std::queue<T> mVarianceQueue;
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

		return *this;
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
		std::queue<T> saveQueue = mQueue;
		T max = std::numeric_limits<T>::lowest();

		for (unsigned int length = 0; length < mCount; length++)
		{
			if (max < saveQueue.front())
			{
				max = saveQueue.front();
				saveQueue.pop();
			}
			else
			{
				saveQueue.pop();
				continue;
			}
		}

		return max;
	}


	template<typename T>
	T SmartQueue<T>::GetMin()
	{
		std::queue<T> saveQueue = mQueue;
		T min = std::numeric_limits<T>::max();

		for (unsigned int length = 0; length < mCount; length++)
		{
			if (min > saveQueue.front())
			{
				min = saveQueue.front();
				saveQueue.pop();
			}
			else
			{
				saveQueue.pop();
			}
		}

		return min;

	}

	template<typename T>
	double SmartQueue<T>::GetAverage()
	{
		std::queue<T> saveQueue = mQueue;
		double average = 0;

		for (unsigned int length = 0; length < mCount; length++)
		{
			average += static_cast<double>(saveQueue.front());
			saveQueue.pop();
		}

		average /= mCount;

		return average;
	}

	template<typename T>
	T SmartQueue<T>::GetSum()
	{
		std::queue<T> saveQueue = mQueue;
		T total = 0;

		for (unsigned int length = 0; length < mCount; length++)
		{
			total += saveQueue.front();
			saveQueue.pop();
		}

		return total;
	}

	template<typename T>
	double SmartQueue<T>::GetVariance()
	{
		std::queue<T> saveQueue = mQueue;
		double average = GetAverage();
		double singleVariance = 0;
		double totalVariance = 0;

		for (unsigned int length = 0; length < mCount; length++)
		{
			singleVariance = average - static_cast<double>(saveQueue.front());
			singleVariance *= singleVariance;
			totalVariance += singleVariance;
			saveQueue.pop();
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