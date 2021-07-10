#include <stack>
#include <limits>

#pragma once

namespace assignment3
{
	template<typename T>
	class SmartStack
	{
	public:
		SmartStack();
		SmartStack(const SmartStack& smartStack);
		SmartStack& operator=(const SmartStack& smartStack);
		void Push(const T& number);
		T Pop();
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();
	private:
		std::stack<T> mStack;
		std::stack<T> mMaxStack;
		std::stack<T> mMinStack;
		T mSum = NULL;
		double mVariance = NULL;
		unsigned int mCount = 0;
	};

	template<typename T>
	SmartStack<T>::SmartStack()
		: mCount(0)
	{
		mMaxStack.push(std::numeric_limits<T>::lowest());
		mMinStack.push(std::numeric_limits<T>::max());
	}

	template<typename T>
	SmartStack<T>::SmartStack(const SmartStack& smartStack)
	{
		mStack = smartStack.mStack;
		mMaxStack = smartStack.mMaxStack;
		mMinStack = smartStack.mMinStack;
		mSum = smartStack.mSum;
		mVariance = smartStack.mVariance;
		mCount = smartStack.mCount;
	}

	template<typename T>
	SmartStack<T>& SmartStack<T>::operator=(const SmartStack& smartStack)
	{
		if (this == &smartStack)
		{
			return *this;
		}
	
		mStack = smartStack.mStack;
		mMaxStack = smartStack.mMaxStack;
		mMinStack = smartStack.mMinStack;
		mSum = smartStack.mSum;
		mVariance = smartStack.mVariance;
		mCount = smartStack.mCount;

		return *this;
	}

	template<typename T>
	void SmartStack<T>::Push(const T& number)
	{
		mStack.push(number);
		mCount++;

		if (number >= mMaxStack.top())
		{
			mMaxStack.push(number);
		}

		if (number <= mMinStack.top())
		{
			mMinStack.push(number);
		}

		mSum += number;

		mVariance += pow(mStack.top(), 2);
	}


	template<typename T>
	T SmartStack<T>::Pop()
	{
		T saveNum = mStack.top();

		mStack.pop();
		mCount--;

		mSum -= saveNum;
		mVariance -= pow(saveNum, 2);

		if (saveNum == mMaxStack.top())
		{
			mMaxStack.pop();
		}

		if (saveNum == mMinStack.top())
		{
			mMinStack.pop();
		}

		if (mCount == 0)
		{
			mSum = NULL;
			mVariance = NULL;
		}

		return saveNum;
	}

	template<typename T>
	T SmartStack<T>::Peek()
	{
		return mStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetMax()
	{
		return mMaxStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetMin()
	{
		return mMinStack.top();
	}

	template<typename T>
	double SmartStack<T>::GetAverage()
	{
		double average = static_cast<double>(mSum);
		average /= mCount;
		
		return average;
	}

	template<typename T>
	T SmartStack<T>::GetSum()
	{
		return mSum;
	}

	template<typename T>
	double SmartStack<T>::GetVariance()
	{
		double variance;
		variance = mVariance / mCount - pow(GetAverage(), 2);

		return variance;
	}

	template<typename T>
	double SmartStack<T>::GetStandardDeviation()
	{	
		return sqrt(GetVariance());
	}

	template<typename T>
	unsigned int  SmartStack<T>::GetCount()
	{
		return mCount;
	}
}