#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle()
	{
		mCount = 0;
		mMaxPassengerCount = 0;
		mPerson = nullptr;
	}

	Vehicle::Vehicle(const Vehicle& vehicle)
	{
		unsigned int maxPassenger = vehicle.GetMaxPassengersCount();
		mPerson = nullptr;
		mCount = vehicle.mCount;
		mMaxPassengerCount = maxPassenger;

		if (mMaxPassengerCount != 0)
		{
			mPerson = new Person * [mMaxPassengerCount];

			for (unsigned int length = 0; length < mCount; length++)
			{
				mPerson[length] = new Person(vehicle.mPerson[length]->GetName().c_str(), vehicle.mPerson[length]->GetWeight());
			}
		}
	}

	Vehicle::Vehicle(unsigned int maxPassengersCount)
	{
		mPerson = nullptr;
		mMaxPassengerCount = maxPassengersCount;
		mCount = 0;

		if (mMaxPassengerCount != 0)
		{
			mPerson = new Person * [mMaxPassengerCount];
		}
	}

	Vehicle::~Vehicle()
	{
		DeletePerson();
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mCount >= mMaxPassengerCount || person == nullptr)
		{
			return false;
		}
		else
		{
			mPerson[mCount] = (Person *)person;
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
				if (length == mCount - 1)
				{
					mPerson[length] = nullptr;
					
				}
				else
				{
					mPerson[length] = mPerson[length + 1];
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
			totalWeight += mPerson[length]->GetWeight();
		}

		return totalWeight;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i >= mCount)
		{
			return NULL;
		}
		else
		{
			return mPerson[i];
		}
	}

	Vehicle& Vehicle::operator=(const Vehicle& vehicle)
	{
		if (this != &vehicle)
		{
			DeletePerson();

			mCount = vehicle.mCount;
			mMaxPassengerCount = vehicle.mMaxPassengerCount;
			mPerson = new Person * [mMaxPassengerCount];

			for (int length = 0; length < mCount; length++)
			{
				mPerson[length] = new Person(vehicle.mPerson[length]->GetName().c_str(), vehicle.mPerson[length]->GetWeight());
			}
		}

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
			else
			{
				continue;
			}
		}

		mCount = 0;
	}

	void Vehicle::DeletePerson()
	{
		for (unsigned int length = 0; length < mCount; length++)
		{
			delete mPerson[length];
		}

		mCount = 0;
		delete[] mPerson;
		mPerson = nullptr;
	}
}