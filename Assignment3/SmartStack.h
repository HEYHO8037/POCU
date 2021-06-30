#include <stack>

#pragma once

template<typename T>
class SmartStack
{
public:
	SmartStack();
	SmartStack(const SmartStack& smartStack);
	void Push(T number);
	void Pop();
	void Peek();
	T GetMax();
	T GetMin();
	T GetAverage();
	T GetSum();
	T GetVariance();
	T GetStandardDeviation();
	T GetCount();
private:
	std::stack<T> mStack;
	int mCount = 0;
};

template<typename T>
SmartStack<T>::SmartStack()
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
void SmartStack<T>::Peek()
{
	mStack.top();
}


template<typename T>
T SmartStack<T>::GetMax()
{
	T max;
	for (unsigned int length = 0; length < mCount; length++)
	{

	}

	return max;
}


template<typename T>
T SmartStack<T>::GetMin()
{
	T min;

	return min;
}