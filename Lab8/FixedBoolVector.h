#include "FixedVector.h"

#pragma once

namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		FixedVector(const FixedVector& fixedVector);
		~FixedVector();
		bool Add(bool bAdd);
		bool Remove(bool bRemove);
		bool Get(unsigned int index);
		bool& operator[](const int index);
		FixedVector operator=(const FixedVector& fixedVector);
		int GetIndex(bool bIndex);
		size_t GetSize();
		size_t GetCapacity();

	private:
		unsigned int mMaxSize;
		unsigned int mCount = 0;
		bool* mStore;
	};

	template<size_t N>
	FixedVector<bool, N>::FixedVector()
	{
		mMaxSize = N;
		mStore = new bool[mMaxSize];
	}

	template<size_t N>
	FixedVector<bool, N>::FixedVector(const FixedVector& fixedVector)
	{
		fixedVector.mMaxSize = mMaxSize;
		mStore = new bool[mMaxSize];

		for (unsigned int length = 0; length < mMaxSize; length++)
		{
			mStore[length] = fixedVector.mStore[length];
		}
	}

	template<size_t N>
	FixedVector<bool, N>::~FixedVector()
	{
		delete[] mStore;
		mStore = nullptr;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Add(bool bAdd)
	{
		if (mCount >= mMaxSize)
		{
			return false;
		}
		else
		{
			mStore[mCount] = bAdd;
			mCount++;

			return true;
		}
	}


	template<size_t N>
	bool FixedVector<bool, N>::Remove(bool bRemove)
	{
		unsigned int saveLength;
		bool bFind = false;

		for (unsigned int length = 0; length < mCount; length++)
		{
			if (mStore[length] == bRemove)
			{
				saveLength = length;
				bFind = true;
				break;
			}
		}

		if (bFind == false)
		{
			return false;
		}
		else
		{
			for (unsigned int length = saveLength; length < mCount; length++)
			{
				if (length == mMaxSize - 1)
				{
					mStore[length] = 0;
				}
				else
				{
					mStore[length] = mStore[length + 1];
				}
			}

			mCount--;
			return true;
		}
	}

	template<size_t N>
	bool FixedVector<bool, N>::Get(unsigned int index)
	{
		return mStore[index];
	}

	template<size_t N>
	bool& FixedVector<bool, N>::operator[](const int index)
	{
		return mStore[index];
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(bool bIndex)
	{
		int index = -1;

		for (unsigned int length = 0; length < mCount; length++)
		{
			if (mStore[length] == bIndex)
			{
				index = length;
				break;
			}
		}

		return index;
	}

	template<size_t N>
	FixedVector<bool, N> FixedVector<bool, N>::operator=(const FixedVector& fixedVector)
	{
		if (mStore != nullptr)
		{
			for (unsigned int length = 0; length < mMaxSize; length++)
			{
				delete mStore[length];
			}

			delete[] mStore;
			mStore = nullptr;
		}

		mMaxSize = fixedVector.mMaxSize;
		mCount = fixedVector.mCount;

		mStore = new bool[mMaxSize];

		for (unsigned int length = 0; length < mCount; length++)
		{
			mStore[length] = fixedVector.mStore[length];
		}
	}

	template<size_t N>
	size_t  FixedVector<bool, N>::GetSize()
	{
		return static_cast<size_t>(mCount);
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetCapacity()
	{
		return static_cast<size_t>(mMaxSize);
	}
}