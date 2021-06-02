#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		:Vehicle(maxPassengersCount)
	{
		mTravelCheck = 3;
	}

	Boatplane::Boatplane(Boatplane& boatPlane)
		: Vehicle(boatPlane)
	{
		mTravelCheck = 3;
	}

	Boatplane::~Boatplane()
	{

	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		double weight = GetTotalPassengerWeight();
		double flySpeed = round(150 * (exp((-weight + 500) / 300)));

		return static_cast<unsigned int>(flySpeed);
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

	unsigned int Boatplane::GetTravelSpeed()
	{
		if (mTravelCheck == 3)
		{
			mTravelCheck--;
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
		double weight = GetTotalPassengerWeight();
		double sailSpeed = round(fmax(800 - (1.7 * weight), 20));

		return static_cast<unsigned int>(sailSpeed);
	}

	Boatplane& Boatplane::operator=(Boatplane& boatPlane)
	{
		mMaxPassengerCount = boatPlane.mMaxPassengerCount;
		mTravelCheck = 3;

		return *this;
	}
}