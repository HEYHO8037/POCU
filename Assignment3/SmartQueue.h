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
		void Enqueue(const T& number);
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
		T mSum = NULL;
		double mVariance = NULL;
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
		mMax = smartQueue.mMax;
		mMin = smartQueue.mMin;
		mSum = smartQueue.mSum;
		mVariance = smartQueue.mVariance;
	}

	template<typename T>
	SmartQueue<T>& SmartQueue<T>::operator=(const SmartQueue& smartQueue)
	{
		if (this == &smartQueue)
		{
			return *this;
		}

		mCount = smartQueue.mCount;
		mMax = smartQueue.mMax;
		mMin = smartQueue.mMin;
		mSum = smartQueue.mSum;
		mVariance = smartQueue.mVariance;

		return *this;
	}


	template<typename T>
	void SmartQueue<T>::Enqueue(const T& number)
	{
		mQueue.push(number);

		mSum += number;
		mVariance += pow(number, 2);
		mCount++;
	}

	template<typename T>
	T SmartQueue<T>::Dequeue()
	{
		T saveTemplate = mQueue.front();

		mQueue.pop();
		mSum -= saveTemplate;
		mVariance -= pow(saveTemplate, 2);
		mCount--;

		if (mCount == 0)
		{
			mSum = NULL;
			mVariance = NULL;
		}

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
		T mMax = std::numeric_limits<T>::lowest();
		std::queue<T> saveQueue = mQueue;

		while (!saveQueue.empty())
		{
			if (saveQueue.front() >= mMax)
			{
				mMax = saveQueue.front();
			}

			saveQueue.pop();
		}

		return mMax;
	}


	template<typename T>
	T SmartQueue<T>::GetMin()
	{
		T mMin = std::numeric_limits<T>::max();
		std::queue<T> saveQueue = mQueue;
		
		while (!saveQueue.empty())
		{
			if (saveQueue.front() <= mMin)
			{
				mMin = saveQueue.front();
			}

			saveQueue.pop();
		}

		return mMin;
	}

	template<typename T>
	double SmartQueue<T>::GetAverage()
	{
		double average = static_cast<double>(mSum);
		average /= mCount;

		return average;
	}

	template<typename T>
	T SmartQueue<T>::GetSum()
	{
		return mSum;
	}

	template<typename T>
	double SmartQueue<T>::GetVariance()
	{
		double variance;
		variance = mVariance / mCount - pow(GetAverage(), 2);

		return variance;
	}

	template<typename T>
	double SmartQueue<T>::GetStandardDeviation()
	{
		return sqrt(GetVariance());
	}

	template<typename T>
	unsigned int  SmartQueue<T>::GetCount()
	{
		return mCount;
	}
}