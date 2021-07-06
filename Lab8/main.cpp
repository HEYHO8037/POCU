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
	FixedVector<bool, 60> f;
	for (int i = 0; i < 60; ++i)
	{
		if (i == 59 || i == 55)
		{
			f.Add(true);
			continue;
		}
		
		f.Add(false);
	}

	f.Remove(false);
	f.Remove(false);
	f.Remove(false);
	f.Remove(true);
	f.Remove(false);
	f.Remove(false);
	f.Remove(false);
	f.Remove(true);

}