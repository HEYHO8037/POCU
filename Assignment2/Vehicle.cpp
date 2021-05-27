#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
	{
		mMaxPassengerCount = maxPassengersCount;
		mPerson = new Person* [mMaxPassengerCount];
	}

	Vehicle::~Vehicle()
	{
		delete[] mPerson;
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
			return true;
		}
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i > mCount)
		{
			return false;
		}
		else
		{
			delete mPerson[i];
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
}