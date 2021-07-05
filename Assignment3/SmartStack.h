#include <stack>
#include <limits>

#pragma once

template<typename T>
class SmartStack
{
public:
	SmartStack();
	SmartStack(const SmartStack& smartStack);
	void Push(T number);
	void Pop();
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
	mStack = smartStack.mStack;
	mCount = smartStack.mCount;
}

template<typename T>
void SmartStack<T>::Push(T number)
{
	mStack.push(number);
	mCount++;
}

template<typename T>
void SmartStack<T>::Pop()
{
	mStack.pop();
	mCount--;
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

	if (mCount == 0)
	{
		return max;
	}
	else
	{
		for (unsigned int length = 0; length < mCount; length++)
		{
			if (max < mStack[length])
			{
				max = mStack[length];
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
T SmartStack<T>::GetMin()
{
	T min =  std::numeric_limits<T>::max();

	if (mCount == 0)
	{
		return min;
	}
	else
	{
		for (unsigned int length = 0; length < mCount; length++)
		{
			if (min > mStack[length])
			{
				min = mStack[length];
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
double SmartStack<T>::GetAverage()
{
	double average = 0;

	for (unsigned int length = 0; length < mCount; length++)
	{
		average += mStack[length];
	}

	average /= mCount;

	return average;
}

template<typename T>
T SmartStack<T>::GetSum()
{
	T total = 0;

	for (unsigned int length = 0; length < mCount; length++)
	{
		total += mStack[length];
	}

	return total;
}

template<typename T>
double SmartStack<T>::GetVariance()
{
	double average = GetAverage();
	double singleVariance;
	double totalVariance;

	for (unsigned int length = 0; length < mCount; length++)
	{
		singleVariance = average - mStack[length];
		singleVariance *= singleVariance;
		totalVariance += singleVariance;
	}
	
	totalVariance /= mCount;

	return totalVariance;
}

template<typename T>
double SmartStack<T>::GetStandardDeviation()
{

	unsigned int rotation = 10;
	double standardDeviation = GetVariance();

	for (unsigned int length = 0; length < rotataion; length++)
	{
		standardDeviation = (standardDeviation + (2 / standardDeviation)) / 2;
	}

	return standardDeviation;
}

template<typename T>
unsigned int  SmartStack<T>::GetCount()
{
	return mCount;
}