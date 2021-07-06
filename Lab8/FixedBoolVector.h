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
		bool Add(const bool& bAdd);
		bool Remove(const bool& bRemove);
		bool Get(unsigned int index);
		bool operator[](unsigned int index);
		FixedVector& operator=(const FixedVector& fixedVector);
		int GetIndex(const bool& bIndex);
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		size_t mSize;
		unsigned int mArray = { 0 };
	};

	template<size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
	{
	}


	template<size_t N>
	FixedVector<bool, N>::FixedVector(const FixedVector& fixedVector)
	{
		mSize = fixedVector.mSize;

		mArray = fixedVector.mArray;
	}

	template<size_t N>
	FixedVector<bool, N>::~FixedVector()
	{
	}

	template<size_t N>
	bool FixedVector<bool, N>::Add(const bool& bAdd)
	{
		if (mSize >= N)
		{
			return false;
		}
		else
		{
			if (bAdd == true)
			{
				mArray |= 1UL << mSize;
				mSize++;
			}
			else
			{
				mArray &= ~(1UL << mSize);
				mSize++;
			}

		}
	}


	template<size_t N>
	bool FixedVector<bool, N>::Remove(const bool& bRemove)
	{
		unsigned int saveLength;
		bool bFind = false;

		for (unsigned int length = 0; length < mSize; length++)
		{
			if ((mArray >> length & 1U) == bRemove)
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
				if ((mArray >> (length + 1) & 1U) == true)
				{
					mArray |= 1UL << length;
				}
				else
				{
					mArray &= ~(1UL << length);
				}
				
			}

			mSize--;
			return true;
		}
	}

	template<size_t N>
	bool FixedVector<bool, N>::Get(unsigned int index)
	{
		return (mArray >> index) & 1U;
	}

	template<size_t N>
	bool FixedVector<bool, N>::operator[](unsigned int index)
	{
		return (mArray >> index) & 1U;
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(const bool& bIndex)
	{
		int index = -1;

		for (unsigned int length = 0; length < mSize; length++)
		{
			if (((mArray >> length) & 1U) == bIndex)
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
		mSize = fixedVector.mSize;

		mArray = fixedVector.mArray;
	}

	template<size_t N>
	size_t  FixedVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetCapacity() const
	{
		return N;
	}
}