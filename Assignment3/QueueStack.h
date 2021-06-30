#pragma once
#include <queue>
#include <stack>

#pragma once

template<typename T>
class QueueStack
{
public:
	QueueStack();
	QueueStack(const QueueStack& queueStack);
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


template<typename T>
QueueStack<T>::QueueStack()
{

}

template<typename T>
QueueStack<T>::QueueStack(const QueueStack& queueStack)
{

}