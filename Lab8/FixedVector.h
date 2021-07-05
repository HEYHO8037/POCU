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
		bool Add(const T& t);
		bool Remove(const T& t);
		T Get(unsigned int index);
		T& operator[](unsigned int index);
		FixedVector& operator=(const FixedVector& fixedVector);
		int GetIndex(T t);
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		size_t mSize;
		T mArray[N];
	};

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mSize(0)
	{
	}

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector(const FixedVector& fixedVector)
	{
		mSize = fixedVector.mSize;

		for (unsigned int length = 0; length < mSize; length++)
		{
			mArray[length] = fixedVector.mArray[length];
		}
	}

	template<typename T, size_t N>
	FixedVector<T, N>::~FixedVector()
	{
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Add(const T& t)
	{
		if (mSize >= N)
		{
			return false;
		}
		else
		{
			mArray[mSize++] = t;

			return true;
		}
	}


	template<typename T, size_t N>
	bool FixedVector<T, N>::Remove(const T& t)
	{
		unsigned int saveLength;
		bool bFind = false;

		for (unsigned int length = 0; length < mSize; length++)
		{
			if (mArray[length] == t)
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
			for (unsigned int length = saveLength; length < mSize - 1; length++)
			{
				mArray[length] = mArray[length + 1];
			}

			mSize--;
			return true;
		}
	}

	template<typename T, size_t N>
	T FixedVector<T, N>::Get(const unsigned int index)
	{
		return mArray[index];
	}

	template<typename T, size_t N>
	T& FixedVector<T, N>::operator[](const unsigned int index)
	{
		return mArray[index];
	}

	template<typename T, size_t N>
	int FixedVector<T, N>::GetIndex(T t)
	{
		int index = -1;

		for (unsigned int length = 0; length < mSize; length++)
		{
			if (mArray[length] == t)
			{
				index = length;
				break;
			}
		}

		return index;
	}

	template<typename T, size_t N>
	FixedVector<T, N>& FixedVector<T, N>::operator=(const FixedVector& fixedVector)
	{
		mSize = fixedVector.mSize;

		for (unsigned int length = 0; length < mSize; length++)
		{
			mArray[length] = fixedVector.mArray[length];
		}

		return *this;
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity() const
	{
		return N;
	}
}