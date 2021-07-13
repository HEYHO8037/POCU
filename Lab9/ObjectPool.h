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
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();

	private:
		ObjectPool(const ObjectPool& objectPool);
		ObjectPool operator=(const ObjectPool& obejctPool) = default;

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

		mObjectArray[mCount] = pT;
		mCount++;
	}

	template<typename T>
	size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return mCount;
	}

	template<typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return (mMaxPoolSize - mCount);
	}
}