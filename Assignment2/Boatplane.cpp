#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
	{
		mMaxPassengerCount = maxPassengersCount;
		mTravelCheck = 3;
	}

	Boatplane::Boatplane(Boatplane& boatPlane)
	{
		mMaxPassengerCount = boatPlane.mMaxPassengerCount;
		mTravelCheck = 3;
	}

	Boatplane::~Boatplane()
	{

	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		return static_cast < unsigned int>(150 * (exp((-GetTotalPassengerWeight() + 500) / 300)));
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		if (GetFlySpeed() > GetSailSpeed())
		{
			return GetFlySpeed();
		}
		else
		{
			return GetSailSpeed();
		}
	}

	unsigned int Boatplane::GetTravelSpeed() const
	{
		if (mTravelCheck == 3)
		{
			return GetMaxSpeed();
		}
		else
		{
			mTravelCheck--;
			if (mTravelCheck == 0)
			{
				mTravelCheck = 3;
			}
			return 0;
		}
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		return static_cast<unsigned int>(fmax(800 - (1.7 * GetTotalPassengerWeight()), 20));
	}

	Boatplane& Boatplane::operator=(Boatplane& boatPlane)
	{
		mMaxPassengerCount = boatPlane.mMaxPassengerCount;
		mTravelCheck = 3;
	}
}