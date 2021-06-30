#pragma once
#include <queue>

#pragma once

template<typename T>
class SmartQueue
{
public:
	SmartQueue();
	SmartQueue(const SmartQueue& smartStack);
	void Enqueue();
	void Dequeue();
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