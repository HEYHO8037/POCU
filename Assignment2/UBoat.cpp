#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
		mTravelCheck = 5;
	}

	UBoat::UBoat(UBoat& uBoat)
		: Vehicle(uBoat)
	{
		mTravelCheck = 5;
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		double weight = GetTotalPassengerWeight();
		double diveSpeed = 500 * log((weight + 150) / 150) + 30;
		diveSpeed += 0.5f;

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
		if (mTravelCheck == 5 || mTravelCheck == 4)
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

	UBoat& UBoat::operator=(UBoat& uBoat)
	{
		DeletePerson();

		mMaxPassengerCount = uBoat.mMaxPassengerCount;
		mTravelCheck = 5;
		mCount = uBoat.mCount;
		mPerson = new Person * [mMaxPassengerCount];

		for (int length = 0; length < mCount; length++)
		{
			AddPassenger(uBoat.mPerson[length]);
		}

		uBoat.ChangeArrayNullptr();
		uBoat.mCount = 0;

		return *this;
	}
}