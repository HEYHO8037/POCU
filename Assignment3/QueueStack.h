#pragma once
#include <queue>
#include <stack>

#pragma once

template<typename T>
class QueueStack
{
public:
	QueueStack<T>();
	QueueStack<T>(const SmartQueue smartStack);
	void Enqueue();
	void Dequeue();
	void Peek();
	T GetMax();
	T GetMin();
	T GetAverage();
	T GetSum();
	T GetCount();
	T GetStackCount();
private:
};