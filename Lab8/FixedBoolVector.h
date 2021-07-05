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
		int GetIndex(bool bIndex);
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		size_t mSize;
		bool mbArray[N];
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

		for (unsigned int length = 0; length < mSize; length++)
		{
			mbArray[length] = fixedVector.mbArray[length];
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
			mbArray[mSize++] = bAdd;
			return true;
		}
	}


	template<size_t N>
	bool FixedVector<bool, N>::Remove(const bool& bRemove)
	{
		unsigned int saveLength;
		bool bFind = false;

		for (unsigned int length = 0; length < mSize; length++)
		{
			if (mbArray[length] == bRemove)
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
				mbArray[length] = mbArray[length + 1];
			}

			mSize--;
			return true;
		}
	}

	template<size_t N>
	bool FixedVector<bool, N>::Get(const unsigned int index)
	{
		return mbArray[index];
	}

	template<size_t N>
	bool FixedVector<bool, N>::operator[](const unsigned int index)
	{
		return mbArray[index];
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(bool bIndex)
	{
		int index = -1;

		for (unsigned int length = 0; length < mSize; length++)
		{
			if (mbArray[length] == bIndex)
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

		for (unsigned int length = 0; length < mSize; length++)
		{
			mbArray[length] = fixedVector.mbArray[length];
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