#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle()
		: mCount(0), mMaxPassengerCount(0), mPerson(nullptr), mTravelTotalSpeed(0)
	{
	}

	Vehicle::Vehicle(const Vehicle& vehicle)
		: mPerson(nullptr), mCount(vehicle.mCount), mMaxPassengerCount(vehicle.mMaxPassengerCount)
		, mTravelTotalSpeed(vehicle.mTravelTotalSpeed)
	{
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
		: mPerson(nullptr), mMaxPassengerCount(maxPassengersCount), mCount(0)
		, mTravelTotalSpeed(0)
	{
		if (mMaxPassengerCount != 0)
		{
			mPerson = new Person * [mMaxPassengerCount];
		}
	}

	Vehicle::~Vehicle()
	{
		deletePerson();
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mCount >= mMaxPassengerCount || person == nullptr)
		{
			return false;
		}
		else
		{
			mPerson[mCount] = (Person*)person;
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
			mPerson[i] = nullptr;

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

	unsigned int Vehicle::GetTotalPassengerWeight() const
	{
		unsigned int totalWeight = 0;

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

	unsigned int Vehicle::GetTravelTotalSpeed()
	{
		return mTravelTotalSpeed;
	}

	void Vehicle::GetTravel()
	{
		mTravelTotalSpeed += GetTravelSpeed();
	}

	Vehicle& Vehicle::operator=(const Vehicle& vehicle)
	{
		if (this != &vehicle)
		{
			deletePerson();

			mCount = vehicle.mCount;
			mMaxPassengerCount = vehicle.mMaxPassengerCount;
			mPerson = new Person * [mMaxPassengerCount];

			for (unsigned int length = 0; length < mCount; length++)
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

	void Vehicle::deletePerson()
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