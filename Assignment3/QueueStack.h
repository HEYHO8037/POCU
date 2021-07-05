#pragma once
#include <queue>
#include <stack>

#pragma once

template<typename T>
class QueueStack
{
public:
	QueueStack();
	QueueStack(unsigned int maxStackSize);
	QueueStack(const QueueStack& queueStack);
	QueueStack& operator=(const QueueStack& queueStack);
	void Enqueue(T number);
	void Dequeue();
	void Peek();
	T GetMax();
	T GetMin();
	T GetAverage();
	T GetSum();
	T GetCount();
	T GetStackCount();
private:
	std::queue<std::stack*> mQueue;
	std::stack<T>* mStack = nullptr;
	unsigned int mMaxStackSize;
	unsigned int mCount = 0;
};


template<typename T>
QueueStack<T>::QueueStack(unsigned int maxStackSize)
	: mMaxStackSize(maxStackSize)
{
}

template<typename T>
QueueStack<T>::QueueStack(const QueueStack& queueStack)
{

}


template<typename T>
void QueueStack<T>::Enqueue(T number)
{
	if (mStack == nullptr)
	{
		mStack = new std::stack<T>();
		mStack->push(number);
		mCount++;
		mQueue.push(mStack);
	}
	else
	{
		mStack->push(number);
		mCount++;

		if (mCount % mMaxStackSize == 0)
		{
			mStack = nullptr;
		}
	}
}