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
		void Push(T number);
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
		std::stack<T> mSumStack;
		std::stack<T> mVarianceStack;
		double mVariance;
		
		unsigned int mCount = 0;
	};


	template<typename T>
	SmartStack<T>::SmartStack()
		: mCount(0)
	{
		mMaxStack.push(std::numeric_limits<T>::lowest());
		mMinStack.push(std::numeric_limits<T>::max());
		mSumStack.push(NULL);
		mVarianceStack.push(NULL);
	}

	template<typename T>
	SmartStack<T>::SmartStack(const SmartStack& smartStack)
	{
		mCount = smartStack.mCount;
		mStack = smartStack.mStack;
	}

	template<typename T>
	SmartStack<T>& SmartStack<T>::operator=(const SmartStack& smartStack)
	{
		if (mStack.size() != 0)
		{
			for (unsigned int length = 0; length < mCount; length++)
			{
				mStack.pop();
			}
		}

		mCount = smartStack.mCount;
		mStack = smartStack.mStack;

		return *this;
	}

	template<typename T>
	void SmartStack<T>::Push(T number)
	{
		T variance;
		mStack.push(number);
		mCount++;

		if (number > mMaxStack.top())
		{
			mMaxStack.push(number);
		}

		if (number < mMinStack.top())
		{
			mMinStack.push(number);
		}
		mSumStack.push(mSumStack.top() + number);

		variance = GetAverage() - mStack.top();
		variance *= variance;
		mVarianceStack.push(variance);
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		T saveNum = mStack.top();
		mStack.pop();
		mSumStack.pop();
		mCount--;

		if (saveNum == mMaxStack.top())
		{
			mMaxStack.pop();
		}

		if (saveNum == mMinStack.top())
		{
			mMinStack.pop();
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
		double average = GetSum();
		average /= mCount;

		return average;
	}

	template<typename T>
	T SmartStack<T>::GetSum()
	{
		return mSumStack.top();
	}

	template<typename T>
	double SmartStack<T>::GetVariance()
	{
		mVarianceStack.top() /= mCount;
		return mVarianceStack.top();
	}

	template<typename T>
	double SmartStack<T>::GetStandardDeviation()
	{
		double x = 2;
		unsigned int rotation = 10;
		double standardDeviation = GetVariance();

		for (unsigned int length = 0; length < rotation; length++)
		{
			x = (x + (standardDeviation / x)) / 2;
		}

		return x;
	}

	template<typename T>
	unsigned int  SmartStack<T>::GetCount()
	{
		return mCount;
	}
}