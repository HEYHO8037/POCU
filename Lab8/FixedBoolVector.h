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
		unsigned int mArraySize = 0;
		uint32_t mArray[N / 32 + 1] = { 0 };
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
		mArraySize = fixedVector.mArraySize;

		for (unsigned int length = 0; length < mArraySize + 1; length++)
		{
			mArray[length] = fixedVector.mArray[length];
		}
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
				mArray[mArraySize] |= 1UL << mSize % 32;
				mSize++;
			}
			else
			{
				mArray[mArraySize] &= ~(1UL << mSize % 32);
				mSize++;
			}

			if (mSize % 32 == 0 && mSize != 0)
			{
				mArraySize++;
			}

		}

		return true;
	}


	template<size_t N>
	bool FixedVector<bool, N>::Remove(const bool& bRemove)
	{
		unsigned int saveLength;
		unsigned int arrayLength = 0;
		bool bFind = false;

		for (unsigned int length = 0; length < mSize; length++)
		{
			if (length % 32 == 0 && length != 0)
			{
				arrayLength++;

			}

			if ((mArray[arrayLength] >> (length % 32) & 1U) == bRemove)
			{
				saveLength = length;
				bFind = true;
				break;
			}
		}

		arrayLength = 0;

		if (bFind == false)
		{
			return false;
		}
		else
		{
			for (unsigned int length = saveLength; length < mSize - 1; length++)
			{
				if (length % 32 == 0 && length != 0)
				{
					arrayLength++;
				}

				if (length % 32 < 31)
				{
					if ((mArray[arrayLength] >> (length % 32 + 1) & 1U) == true)
					{
						mArray[arrayLength] |= 1UL << (length % 32);
					}
					else
					{
						mArray[arrayLength] &= ~(1UL << (length % 32));
					}
				}
				else if (length % 32 == 31)
				{
					if ((mArray[arrayLength + 1] >> (length % 32 + 1) & 1U) == true)
					{
						mArray[arrayLength] |= 1UL << (length % 32);
					}
					else
					{
						mArray[arrayLength] &= ~(1UL << (length % 32));
					}

				}
			}

			mSize--;
			return true;
		}
	}

	template<size_t N>
	bool FixedVector<bool, N>::Get(unsigned int index)
	{
		unsigned int size = index / 32;
		return (mArray[size] >> index % 32) & 1U;
	}

	template<size_t N>
	bool FixedVector<bool, N>::operator[](unsigned int index)
	{
		unsigned int size = index / 32;
		return (mArray[size] >> index % 32) & 1U;
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(const bool& bIndex)
	{
		int index = -1;
		unsigned int arrayLength = 0;

		for (unsigned int length = 0; length < mSize; length++)
		{
			if (length % 32 == 0 && length != 0)
			{
				arrayLength++;
			}

			if (((mArray[arrayLength] >> length % 32) & 1U) == bIndex)
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
		mArraySize = fixedVector.mArraySize;

		for (unsigned int length = 0; length < mArraySize + 1; length++)
		{
			mArray[length] = fixedVector.mArray[length];
		}
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