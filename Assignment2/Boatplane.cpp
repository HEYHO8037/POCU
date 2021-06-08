#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		mTravelCheck = 4;
	}

	Boatplane::Boatplane(const Boatplane& boatPlane)
		: Vehicle(boatPlane)
	{
		mTravelCheck = 4;
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		double weight = GetTotalPassengerWeight();
		double flySpeed = 150 * (exp((-weight + 500) / 300));
		flySpeed = round(flySpeed);

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
		if (mTravelCheck == 4)
		{
			mTravelCheck--;
			return GetMaxSpeed();
		}
		else
		{
			mTravelCheck--;
			if (mTravelCheck == 0)
			{
				mTravelCheck = 4;
			}
			return 0;
		}
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		double weight = GetTotalPassengerWeight();
		double sailSpeed = fmax(800 - (1.7 * weight), 20);
		sailSpeed = round(sailSpeed);

		return static_cast<unsigned int>(sailSpeed);
	}

	void Boatplane::ResetTravelCheck()
	{
		mTravelCheck = 4;
	}

	Boatplane& Boatplane::operator=(const Boatplane& boatPlane)
	{
		if (this != &boatPlane)
		{
			deletePerson();

			mMaxPassengerCount = boatPlane.mMaxPassengerCount;
			mTravelCheck = 3;
			mCount = boatPlane.mCount;
			mTravelTotalSpeed = boatPlane.mTravelTotalSpeed;

			if (mMaxPassengerCount != 0)
			{
				mPerson = new Person * [mMaxPassengerCount];

				for (unsigned int length = 0; length < mCount; length++)
				{
					mPerson[length] = new Person(boatPlane.mPerson[length]->GetName().c_str(), boatPlane.mPerson[length]->GetWeight());
				}
			}
		}

		return *this;
	}
}