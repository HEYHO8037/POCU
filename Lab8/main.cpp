#include <cassert>
#include <vector>
#include <bitset>
#include <ctime>
#include <iostream>
#include "FixedVector.h"
#include "FixedBoolVector.h"
using namespace lab8;

int main()
{
	FixedVector<bool, 32> v1;
	v1.Add(true);
	v1.Add(true);
	v1.Add(true);
	v1.Add(true);
	v1.Remove(true);
	v1.GetSize();
	v1.GetCapacity();
}