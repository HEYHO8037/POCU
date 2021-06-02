#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
		mTravelCheck = 5;
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		double weight = GetTotalPassengerWeight();
		double driveSpeed = round(fmax((-pow((weight / 15), 3) + 2 * weight + 400), 0));

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

	Motorcycle& Motorcycle::operator=(Motorcycle& motorCycle)
	{
		mMaxPassengerCount = motorCycle.mMaxPassengerCount;
		mTravelCheck = 5;

		return *this;
	}
}