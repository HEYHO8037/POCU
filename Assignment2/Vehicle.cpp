#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle()
	{
		mCount = 0;
		mMaxPassengerCount = 0;
		mPerson = nullptr;
	}

	Vehicle::Vehicle(Vehicle& vehicle)
	{
		unsigned int maxPassenger = vehicle.GetMaxPassengersCount();
		if (this != &vehicle)
		{
			mPerson = new const Person* [maxPassenger];
			mCount = vehicle.mCount;

			for (int length = 0; length < maxPassenger; length++)
			{
				mPerson[length] = vehicle.mPerson[length];
			}

			vehicle.ChangeArrayNullptr();
		}
	}

	Vehicle::Vehicle(unsigned int maxPassengersCount)
	{
		mMaxPassengerCount = maxPassengersCount;
		mPerson = new const Person* [mMaxPassengerCount];
	}

	Vehicle::~Vehicle()
	{
		if (mPerson[0] != nullptr)
		{
			delete[] mPerson;
		}
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mCount > mMaxPassengerCount || person == nullptr)
		{
			return false;
		}
		else
		{
			mPerson[mCount] = person;
			mCount++;
			return true;
		}
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i >= mCount)
		{
			return false;
		}
		else
		{
			delete mPerson[i];

			for (unsigned int length = i; length < mCount; length++)
			{
				if (length != mCount - 1)
				{
					mPerson[length] = mPerson[length + 1];
				}
				else
				{
					mPerson[length] = nullptr;
				}
			}

			mCount--;
			return true;
		}
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mCount;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengerCount;
	}

	int Vehicle::GetTotalPassengerWeight() const
	{
		int totalWeight = 0;

		for (unsigned int length = 0; length < mCount; length++)
		{
			totalWeight = mPerson[length]->GetWeight();
		}

		return totalWeight;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i > mCount)
		{
			return NULL;
		}
		else
		{
			return mPerson[i];
		}
	}

	Vehicle& Vehicle::operator=(Vehicle& vehicle)
	{
		if (mCount != 0)
		{
			delete[] mPerson;
		}

		mCount = vehicle.mCount;
		mMaxPassengerCount = vehicle.mMaxPassengerCount;
		mPerson = new const Person * [mMaxPassengerCount];


		for (unsigned int length = 0; length < vehicle.mMaxPassengerCount; length++)
		{
			mPerson[length] = vehicle.mPerson[length];
		}

		vehicle.mPerson = nullptr;

		return *this;
	}

	void Vehicle::ChangeArrayNullptr()
	{
		for (unsigned int length = 0; length < mCount; length++)
		{
			if (mPerson[length] != nullptr)
			{
				mPerson[length] = nullptr;
			}
		}

		mCount = 0;
	}
}