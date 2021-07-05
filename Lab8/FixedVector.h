#pragma once

namespace lab8
{
	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		FixedVector(const FixedVector& fixedVector);
		~FixedVector();
		bool Add(T t);
		bool Remove(T t);
		T Get(unsigned int index);
		T& operator[](const int index);
		FixedVector operator=(const FixedVector& fixedVector);
		int GetIndex(T t);
		size_t GetSize();
		size_t GetCapacity();

	private:
		unsigned int mCount = 0;
		T mStore[N];
	};

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector()
	{
		mMaxSize = N;
	}

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector(const FixedVector& fixedVector)
	{
		mMaxSize = fixedVector.mMaxSize;
		mCount = fixedVector.mCount;

		for (unsigned int length = 0; length < mMaxSize; length++)
		{
			mStore[length] = fixedVector.mStore[length];
		}
	}

	template<typename T, size_t N>
	FixedVector<T, N>::~FixedVector()
	{
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Add(T t)
	{
		if (mCount >= mMaxSize)
		{
			return false;
		}
		else
		{
			mStore[mCount] = t;
			mCount++;

			return true;
		}
	}


	template<typename T, size_t N>
	bool FixedVector<T, N>::Remove(T t)
	{
		unsigned int saveLength;
		bool bFind = false;

		for (unsigned int length = 0; length < mCount; length++)
		{
			if (mStore[length] == t)
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
				mStore[length] = mStore[length + 1];
			}

			mCount--;
			return true;
		}
	}

	template<typename T, size_t N>
	T FixedVector<T, N>::Get(unsigned int index)
	{
		return mStore[index];
	}

	template<typename T, size_t N>
	T& FixedVector<T, N>::operator[](const int index)
	{
		return mStore[index];
	}

	template<typename T, size_t N>
	int FixedVector<T, N>::GetIndex(T t)
	{
		int index = -1;

		for (unsigned int length = 0; length < mCount; length++)
		{
			if (mStore[length] == t)
			{
				index = length;
				break;
			}
		}

		return index;
	}

	template<typename T, size_t N>
	FixedVector<T, N> FixedVector<T, N>::operator=(const FixedVector& fixedVector)
	{
		mMaxSize = fixedVector.mMaxSize;
		mCount = fixedVector.mCount;

		for (unsigned int length = 0; length < mCount; length++)
		{
			mStore[length] = fixedVector.mStore[length];
		}
	}

	template<typename T, size_t N>
	size_t  FixedVector<T, N>::GetSize()
	{
		return static_cast<size_t>(mCount);
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity()
	{
		return static_cast<size_t>(mMaxSize);
	}
}