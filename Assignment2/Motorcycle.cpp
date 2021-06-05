#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
		mTravelCheck = 5;
	}

	Motorcycle::Motorcycle(const Motorcycle& motorCycle)
		: Vehicle(motorCycle)
	{
		mTravelCheck = 5;
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		double weight = GetTotalPassengerWeight();
		double driveSpeed = fmax((-pow((weight / 15), 3) + 2 * weight + 400), 0);
		driveSpeed += 0.5f;

		return static_cast<unsigned int>(driveSpeed);
	}

	unsigned int Motorcycle::GetTravelSpeed()
	{
		if (mTravelCheck == 0)
		{
			mTravelCheck = 5;
			return 0;
		}
		else
		{
			mTravelCheck--;
			return GetMaxSpeed();
		}
	}
	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	Motorcycle& Motorcycle::operator=(const Motorcycle& motorCycle)
	{
		if (this != &motorCycle)
		{
			DeletePerson();

			mMaxPassengerCount = motorCycle.mMaxPassengerCount;
			mTravelCheck = 5;
			mCount = motorCycle.mCount;

			if (mMaxPassengerCount != 0)
			{
				mPerson = new Person * [mMaxPassengerCount];

				for (unsigned int length = 0; length < mCount; length++)
				{
					mPerson[length] = new Person(motorCycle.mPerson[length]->GetName().c_str(), motorCycle.mPerson[length]->GetWeight());
				}
			}

		}

		return *this;
	}
}