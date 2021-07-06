#pragma once
#include <queue>
#include <stack>

#pragma once
namespace assignment3
{
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
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount();
		unsigned int GetStackCount();
	private:
		std::queue< std::stack<T>* > mQueue;
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

	template<typename T>
	void QueueStack<T>::Dequeue()
	{
		std::stack<T>* saveStack;
		saveStack = mQueue.front();
		saveStack->pop();

		if (saveStack->size() == 0)
		{
			delete[] mQueue.front();
			mQueue.pop();
		}
	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		std::stack<T>* saveStack;
		saveStack = mQueue.front();

		return saveStack->top();
	}

	template<typename T>
	T QueueStack<T>::GetMax()
	{
		T max = std::numeric_limits<T>::min();

		if (mCount == 0)
		{
			return max;
		}
		else
		{
			std::queue<std::stack<T>* >::iterator iter;

			while (!mQueue.empty())
			{
				mQueue.front()
					for (unsigned int innerLength = 0; length < mStack->size(); innerLength++)
					{
						if (max < mStack[innerLength])
						{
							max = mStack[innerLength];
						}

					}

				mQueue.front

			}


			return max;
		}
	}

	template<typename T>
	T QueueStack<T>::GetMin()
	{

	}

	template<typename T>
	double QueueStack<T>::GetAverage()
	{

	}

	template<typename T>
	T QueueStack<T>::GetSum()
	{

	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount()
	{
		return;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetStackCount()
	{
		return;
	}
}