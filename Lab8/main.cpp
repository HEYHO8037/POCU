﻿#include <cassert>
#include <iostream>

#include "FixedVector.h"
#include "FixedBoolVector.h"

using namespace lab8;

int main()
{

	FixedVector<bool, 34> fv;
	assert(!fv.Remove(false));
	assert(!fv.Remove(true));
	assert(fv.GetIndex(false) == -1);
	assert(fv.GetIndex(true) == -1);

	// 명세에 index는 항상 범위 내에 있다했고 빌드봇은 이런 테스트 하지 않음.
	//assert(!fv[0]);

	// false 0~31 [0]
	for (size_t i = 0; i != 32; ++i)
	{
		fv.Add(false);
	}
	fv.Add(true);
	fv.Add(true);
	assert(!fv.Get(31));
	assert(fv.Get(31) == fv[31]);
	assert(fv.Get(32));
	assert(fv.Get(32) == fv[32]);
	assert(fv.Get(33));
	assert(fv.Get(33) == fv[33]);
	assert(fv.GetSize() == 34);
	fv.Remove(false);
	assert(fv.Get(31));
	assert(fv.Get(32));
	assert(fv.GetSize() == 33);

		FixedVector<bool, 64> fv2;
		for (size_t i = 0; i != 4; ++i)
		{
			assert(fv2.Add(true));
			assert(fv2.Add(true));
			assert(fv2.Add(true));
			assert(fv2.Add(true));
			assert(fv2.Add(true)); 
			assert(fv2.Add(true));
			assert(fv2.Add(true));
			assert(fv2.Add(true));
			assert(fv2.Add(false));
			assert(fv2.Add(false));
			assert(fv2.Add(false)); 
			assert(fv2.Add(false));
			assert(fv2.Add(false));
			assert(fv2.Add(false));
			assert(fv2.Add(false));
			assert(fv2.Add(false));
		}

		assert(!fv2.Add(true));

		for (size_t i = 0; i != 8; ++i)
		{
			assert(fv2.Remove(true));
		}
		for (size_t i = 0; i != 56; ++i)
		{
			if (i < 8)
			{
				assert(!fv2.Get(i));
			}
			else if (i < 16)
			{
				assert(fv2.Get(i));
			}
			else if (i < 24)
			{
				assert(!fv2.Get(i));
			}
			else if (i < 32)
			{
				assert(fv2.Get(i));
			}
			else if (i < 40)
			{
				assert(!fv2.Get(i));
			}
			else if (i < 48)
			{
				assert(fv2.Get(i));
			}
			else if (i < 56)
			{
				assert(!fv2.Get(i));
			}
		}
	
		for (size_t i = 0; i != 32; ++i)
		{
			assert(fv2.Remove(false));
		}
	assert(fv2.GetCapacity() == 64);
	assert(fv2.GetSize() == 24);
	assert(fv2.GetIndex(true) == 0);
	assert(fv2.GetIndex(false) == -1);
		for (size_t i = 0; i != 24; ++i)
		{
			assert(fv2.Remove(true));
		}
	assert(fv2.GetCapacity() == 64);
	assert(fv2.GetSize() == 0);
	assert(fv2.GetIndex(true) == -1);
	assert(!fv2.Remove(true));
	assert(!fv2.Remove(false));
	assert(fv2.GetIndex(true) == -1);
	assert(fv2.GetIndex(false) == -1);


}