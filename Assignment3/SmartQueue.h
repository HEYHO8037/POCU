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
		std::stack<T> mMaxStack;
		std::stack<T> mMinStack;
		T mSum;
		T mVariance;
	};

	template<typename T>
	SmartQueue<T>::SmartQueue()
	{
		mMaxStack.push(std::numeric_limits<T>::lowest());
		mMinStack.push(std::numeric_limits<T>::max());
	}

	template<typename T>
	SmartQueue<T>::SmartQueue(const SmartQueue& smartQueue)
	{
		mQueue = smartQueue.mQueue;
		mMaxStack = smartQueue.mMaxStack;
		mMinStack = smartQueue.mMinStack;
	}

	template<typename T>
	SmartQueue<T>& SmartQueue<T>::operator=(const SmartQueue& smartQueue)
	{
		mQueue = smartQueue.mQueue;
		mMaxStack = smartQueue.mMaxStack;
		mMinStack = smartQueue.mMinStack;

		return *this;
	}


	template<typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		mQueue.push(number);
		mSum += number;
		mVariance += static_cast<T>(pow(number, 2));

		if (mMaxStack.top() <= number)
		{
			mMaxStack.push(number);
		}

		if (mMinStack.top() >= number)
		{
			mMinStack.push(number);
		}
	}

	template<typename T>
	T SmartQueue<T>::Dequeue()
	{
		T saveNum = mQueue.front();
		mQueue.pop();
		mSum -= saveNum;
		mVariance -= static_cast<T>(pow(saveNum, 2));

		if (mMaxStack.top() == saveNum)
		{
			mMaxStack.pop();
		}

		if (mMinStack.top() == saveNum)
		{
			mMinStack.pop();
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
		return mMaxStack.top();
	}


	template<typename T>
	T SmartQueue<T>::GetMin()
	{
		return mMinStack.top();
	}

	template<typename T>
	double SmartQueue<T>::GetAverage()
	{
		double average = static_cast<double>(GetSum());
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