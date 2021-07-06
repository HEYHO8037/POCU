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
		unsigned int mCount = 0;
	};


	template<typename T>
	SmartStack<T>::SmartStack()
		: mCount(0)
	{
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

	}

	template<typename T>
	void SmartStack<T>::Push(T number)
	{
		mStack.push(number);
		mCount++;
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		T saveNum = mStack.top();
		mStack.pop();
		mCount--;

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
		T max = std::numeric_limits<T>::min();

		std::stack<T> saveStack = mStack;

		if (mCount == 0)
		{
			return max;
		}
		else
		{
			for (unsigned int length = 0; length < mCount; length++)
			{
				if (max < saveStack.top())
				{
					max = saveStack.top();
					saveStack.pop();
				}
				else
				{
					saveStack.pop();
					continue;
				}
			}

			return max;
		}
	}


	template<typename T>
	T SmartStack<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();
		std::stack<T> saveStack = mStack;

		if (mCount == 0)
		{
			return min;
		}
		else
		{
			for (unsigned int length = 0; length < mCount; length++)
			{
				if (min > saveStack.top())
				{
					min = saveStack.top();
					saveStack.pop();
				}
				else
				{
					saveStack.pop();
					continue;
				}
			}

			return min;
		}
	}

	template<typename T>
	double SmartStack<T>::GetAverage()
	{
		double average = 0;
		std::stack<T> saveStack = mStack;

		for (unsigned int length = 0; length < mCount; length++)
		{
			average += saveStack.top();
			saveStack.pop();
		}

		average /= mCount;

		return average;
	}

	template<typename T>
	T SmartStack<T>::GetSum()
	{
		T total = 0;
		std::stack<T> saveStack = mStack;

		for (unsigned int length = 0; length < mCount; length++)
		{
			total += saveStack.top();
			saveStack.pop();
		}

		return total;
	}

	template<typename T>
	double SmartStack<T>::GetVariance()
	{
		std::stack<T> saveStack = mStack;
		double average = GetAverage();
		double singleVariance = 0;
		double totalVariance = 0;

		for (unsigned int length = 0; length < mCount; length++)
		{
			singleVariance = average - saveStack.top();
			singleVariance *= singleVariance;
			totalVariance += singleVariance;
			saveStack.pop();
		}

		totalVariance /= mCount;

		return totalVariance;
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