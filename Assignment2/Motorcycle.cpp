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
		return static_cast<unsigned int>(fmax((-pow((GetTotalPassengerWeight() / 15), 3) + 2 * GetTotalPassengerWeight() + 400), 0));
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