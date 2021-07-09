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
		std::queue<double> mQueue;
		std::queue<double> mMaxQueue;
		std::queue<double> mMinQueue;
		T mSum;
		T mVariance;
	};

	template<typename T>
	SmartQueue<T>::SmartQueue()
	{
	}

	template<typename T>
	SmartQueue<T>::SmartQueue(const SmartQueue& smartQueue)
	{
		mQueue = smartQueue.mQueue;
		mMaxQueue = smartQueue.mMaxQueue;
		mMinQueue = smartQueue.mMinQueue;
	}

	template<typename T>
	SmartQueue<T>& SmartQueue<T>::operator=(const SmartQueue& smartQueue)
	{
		if (this == &smartQueue)
		{
			return *this;
		}

		mQueue = smartQueue.mQueue;
		mMaxQueue = smartQueue.mMaxQueue;
		mMinQueue = smartQueue.mMinQueue;

		return *this;
	}


	template<typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		mQueue.push(number);
		mSum += number;
		mVariance += static_cast<T>(pow(number, 2));

		if (mMaxQueue.empty())
		{
			mMaxQueue.push(number);
		}
		else if (mMaxQueue.back() <= number)
		{
			mMaxQueue.push(number);
		}

		if (mMinQueue.empty())
		{
			mMinQueue.push(number);
		}
		else if (mMinQueue.back() >= number)
		{
			mMinQueue.push(number);
		}
	}

	template<typename T>
	T SmartQueue<T>::Dequeue()
	{
		T saveNum = mQueue.front();
		mQueue.pop();
		mSum -= saveNum;
		mVariance -= static_cast<T>(pow(saveNum, 2));

		if (mMaxQueue.front() == saveNum)
		{
			mMaxQueue.pop();
		}

		if (mMinQueue.front() == saveNum)
		{
			mMinQueue.pop();
		}

		return saveNum;
	}

	template<typename T>
	T SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}

	template<typename T>
	T SmartQueue<T>::GetMax()
	{
		return mMaxQueue.front();
	}


	template<typename T>
	T SmartQueue<T>::GetMin()
	{
		return mMinQueue.front();
	}

	template<typename T>
	double SmartQueue<T>::GetAverage()
	{
		double average = GetSum();
		average /= mQueue.size();

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
		variance = mVariance / mQueue.size() - pow(GetAverage(), 2);

		return variance;
	}

	template<typename T>
	double SmartQueue<T>::GetStandardDeviation()
	{
		double standardDeviation = sqrt(GetVariance());

		return standardDeviation;
	}

	template<typename T>
	unsigned int  SmartQueue<T>::GetCount()
	{
		return static_cast<unsigned int>(mQueue.size());
	}
}