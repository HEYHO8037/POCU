#pragma once

#include <memory>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		Storage(const Storage& storage);
		Storage(Storage&& storage);


		Storage& operator=(const Storage& storage);
		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;

	private:
		std::unique_ptr<T[]> mArray;
		unsigned int mLength;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
	{
		mArray = std::make_unique<T[]>(length);
		mLength = length;

		for (unsigned int myLength = 0; myLength < length; myLength++)
		{
			mArray[myLength] = 0;
		}
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
	{
		mArray = std::make_unique<T[]>(length);
		mLength = length;

		for (unsigned int myLength = 0; myLength < length; myLength++)
		{
			mArray[myLength] = initialValue;
		}
	}

	template<typename T>
	Storage<T>::Storage(const Storage& storage)
	{
		mLength = storage.mLength;
		mArray = std::make_unique<T[]>(mLength);

		for (unsigned int myLength = 0; myLength < mLength; myLength++)
		{
			mArray[myLength] = storage.mArray[myLength];
		}
	}

	template<typename T>
	Storage<T>::Storage(Storage&& storage)
	{
		mArray = std::move(storage.mArray);
		mLength = storage.mLength;
		storage.mLength = 0;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(const Storage& storage)
	{
		if (this == *stoarge)
		{
			return *this;
		}

		mLength = storage.mLength;
		mArray = std::make_unique<T[]>(mLength);

		for (unsigned int myLength = 0; myLength < mLength; myLength++)
		{
			mArray[myLength] = storage.mArray[myLength];
		}

		return *this;
	}


	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index >= mLength)
		{
			return false;
		}
		else
		{
			mArray[index] = data;
			return true;
		}
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return std::move(mArray);
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mLength;
	}
}