#include <stack>

#pragma once

template<typename T>
class SmartStack
{
public:
	SmartStack<T>();
	SmartStack<T>(const SmartStack smartStack);
	void Push();
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
};