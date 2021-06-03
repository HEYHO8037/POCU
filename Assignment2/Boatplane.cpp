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
		double flySpeed = 150 * (exp((-weight + 500) / 300));
		flySpeed += 0.5f;

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
		double sailSpeed = fmax(800 - (1.7 * weight), 20);
		sailSpeed += 0.5f;

		return static_cast<unsigned int>(sailSpeed);
	}

	Boatplane& Boatplane::operator=(Boatplane& boatPlane)
	{
		DeletePerson();

		mMaxPassengerCount = boatPlane.mMaxPassengerCount;
		mTravelCheck = 3;
		mCount = boatPlane.mCount;
		mPerson = new const Person * [mMaxPassengerCount];

		for (unsigned int length = 0; length < mCount; length++)
		{
			AddPassenger(boatPlane.mPerson[length]);
		}

		boatPlane.ChangeArrayNullptr();
		boatPlane.mCount = 0;

		return *this;
	}
}