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
		bool Get(const unsigned int index);
		bool& operator[](const unsigned int index);
		FixedVector& operator=(const FixedVector& fixedVector);
		int GetIndex(bool bIndex);
		size_t GetSize();
		size_t GetCapacity();

	private:
		unsigned int mMaxSize;
		unsigned int mCount = 0;
		bool mbStore[N];
	};

	template<size_t N>
	FixedVector<bool, N>::FixedVector()
	{
		mMaxSize = N;
	}

	template<size_t N>
	FixedVector<bool, N>::FixedVector(const FixedVector& fixedVector)
	{
		mMaxSize = fixedVector.mMaxSize;
		mCount = fixedVector.mCount;

		for (unsigned int length = 0; length < mMaxSize; length++)
		{
			mbStore[length] = fixedVector.mbStore[length];
		}
	}

	template<size_t N>
	FixedVector<bool, N>::~FixedVector()
	{
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
			mbStore[mCount] = bAdd;
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
			if (mbStore[length] == bRemove)
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
			for (unsigned int length = saveLength; length < mCount - 1; length++)
			{
				mbStore[length] = mbStore[length + 1];
			}

			mCount--;
			return true;
		}
	}

	template<size_t N>
	bool FixedVector<bool, N>::Get(const unsigned int index)
	{
		return mbStore[index];
	}

	template<size_t N>
	bool& FixedVector<bool, N>::operator[](const unsigned int index)
	{
		return mbStore[index];
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(bool bIndex)
	{
		int index = -1;

		for (unsigned int length = 0; length < mCount; length++)
		{
			if (mbStore[length] == bIndex)
			{
				index = length;
				break;
			}
		}

		return index;
	}

	template<size_t N>
	FixedVector<bool, N>& FixedVector<bool, N>::operator=(const FixedVector& fixedVector)
	{
		mMaxSize = fixedVector.mMaxSize;
		mCount = fixedVector.mCount;

		for (unsigned int length = 0; length < mCount; length++)
		{
			mbStore[length] = fixedVector.mbStore[length];
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