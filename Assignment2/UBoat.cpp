#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
		mTravelCheck = 6;
	}

	UBoat::UBoat(const UBoat& uBoat)
		: Vehicle(uBoat)
	{
		mTravelCheck = 6;
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		double weight = GetTotalPassengerWeight();
		double diveSpeed = 500 * log((weight + 150) / 150) + 30;
		diveSpeed = round(diveSpeed);

		return static_cast<unsigned int>(diveSpeed);
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		double weight = GetTotalPassengerWeight();
		double sailSpeed = fmax((550 - weight / 10), 200);
		sailSpeed += 0.5;

		return static_cast<unsigned int>(sailSpeed);
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		if (GetDiveSpeed() > GetSailSpeed())
		{
			return GetDiveSpeed();
		}
		else
		{
			return GetSailSpeed();
		}
	}
	unsigned int UBoat::GetTravelSpeed()
	{
		if (mTravelCheck == 6 || mTravelCheck == 5)
		{
			mTravelCheck--;
			return GetMaxSpeed();
		}
		else
		{
			mTravelCheck--;
			if (mTravelCheck == 0)
			{
				mTravelCheck = 5;
			}
			return 0;
		}
	}

	void UBoat::ResetTravelCheck()
	{
		mTravelCheck = 6;
	}

	UBoat& UBoat::operator=(const UBoat& uBoat)
	{
		if (this != &uBoat)
		{
			deletePerson();

			mMaxPassengerCount = uBoat.mMaxPassengerCount;
			mTravelCheck = 5;
			mCount = uBoat.mCount;
			mTravelTotalSpeed = uBoat.mTravelTotalSpeed;

			if (mMaxPassengerCount != 0)
			{
				mPerson = new Person * [mMaxPassengerCount];

				for (unsigned int length = 0; length < mCount; length++)
				{
					AddPassenger(new Person(uBoat.mPerson[length]->GetName().c_str(), uBoat.mPerson[length]->GetWeight()));
				}
			}
		}

		return *this;
	}
}