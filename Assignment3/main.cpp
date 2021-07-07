#include <cassert>
#include <cmath>

#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"

using namespace assignment3;

int main()
{
	SmartStack<int> st;
	st.Push(4);
	st.Push(4);
	st.Push(4);
	st.Push(4);
	st.GetMax();
	st.GetMin();
	st.Pop();
	st.Pop();

	QueueStack<int> qs(3);
	qs.Enqueue(1);
	qs.Enqueue(2);
	qs.Enqueue(3);
	qs.Enqueue(4);
	qs.Peek();
	qs.Dequeue();
	qs.Dequeue();
	qs.Dequeue();
	qs.GetMax();
	qs.GetAverage();
	qs.GetMin();
	qs.GetSum();
	qs.GetCount();
	qs.GetStackCount();
	return 0;
}