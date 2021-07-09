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
		std::stack<double> mStack;
		std::stack<double> mMaxStack;
		std::stack<double> mMinStack;
		double mSum = NULL;
		double mVariance = NULL;
		unsigned int mCount = 0;
	};

	template<typename T>
	SmartStack<T>::SmartStack()
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
	void SmartStack<T>::Push(T number)
	{
		mStack.push(static_cast<double>(number));
		mCount++;

		if (number >= mMaxStack.top())
		{
			mMaxStack.push(static_cast<double>(number));
		}

		if (number <= mMinStack.top())
		{
			mMinStack.push(static_cast<double>(number));
		}

		mSum += static_cast<double>(number);

		mVariance += pow(mStack.top(), 2);
	}


	template<typename T>
	T SmartStack<T>::Pop()
	{
		double saveNum = mStack.top();

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

		return static_cast<T>(saveNum);
	}

	template<typename T>
	T SmartStack<T>::Peek()
	{
		return static_cast<T>(mStack.top());
	}

	template<typename T>
	T SmartStack<T>::GetMax()
	{
		return static_cast<T>(mMaxStack.top());
	}

	template<typename T>
	T SmartStack<T>::GetMin()
	{
		return static_cast<T>(mMinStack.top());
	}

	template<typename T>
	double SmartStack<T>::GetAverage()
	{
		double average = mSum;
		average /= mCount;
		
		return average;
	}

	template<typename T>
	T SmartStack<T>::GetSum()
	{
		return static_cast<T>(mSum);
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
		double standardDeviation = sqrt(GetVariance());
		
		return standardDeviation;
	}

	template<typename T>
	unsigned int  SmartStack<T>::GetCount()
	{
		return mCount;
	}
}