#pragma once

namespace lab9
{
	template<typename T>
	class ObjectPool
	{
	public:
		ObjectPool(size_t maxPoolSize);
		~ObjectPool();
		T* Get();
		void Return(T* pT);
		size_t GetFreeObjectCount() const;
		size_t GetMaxFreeObjectCount() const;

	private:
		ObjectPool(const ObjectPool& objectPool);
		ObjectPool& operator=(const ObjectPool& obejctPool);

		unsigned int mMaxPoolSize;
		T** mObjectArray;
		unsigned int mCount;
	};


	template<typename T>
	ObjectPool<T>::ObjectPool(size_t maxPoolSize)
	{
		mMaxPoolSize = maxPoolSize;
		mCount = 0;
		mObjectArray = new T*[mMaxPoolSize];

	}

	template<typename T>
	ObjectPool<T>::~ObjectPool()
	{
		for (unsigned int length = 0; length < mCount; length++)
		{
			delete mObjectArray[length];
		}

		delete[] mObjectArray;
	}

	template<typename T>
	T* ObjectPool<T>::Get()
	{
		if (mCount == 0)
		{
			return new T;
		}

		T* getArray = mObjectArray[0];

		for (unsigned int length = 0; length < mCount - 1; length++)
		{
			mObjectArray[length] = mObjectArray[length + 1];
		}

		mObjectArray[mCount - 1] = nullptr;
		mCount--;

		return getArray;
	}

	template<typename T>
	void ObjectPool<T>::Return(T* pT)
	{
		if (mCount == mMaxPoolSize)
		{
			delete pT;
		}
		else
		{
			mObjectArray[mCount] = pT;
			mCount++;
		}
	}

	template<typename T>
	size_t ObjectPool<T>::GetFreeObjectCount() const
	{
		return mCount;
	}

	template<typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount() const
	{
		return mMaxPoolSize;
	}
}