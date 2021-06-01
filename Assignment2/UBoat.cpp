#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
	{
		mMaxPassengerCount = 50;
		mTravelCheck = 5;
	}

	UBoat::UBoat(UBoat& uBoat)
	{
		mMaxPassengerCount = uBoat.mMaxPassengerCount;
		mTravelCheck = 5;
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		return static_cast<unsigned int>(500 * log((GetTotalPassengerWeight() + 150) / 150) + 30);
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		return static_cast<unsigned int>(fmax((550 - GetTotalPassengerWeight() / 10), 200));
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
	unsigned int UBoat::GetTravelSpeed() const
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
		mMaxPassengerCount = uBoat.mMaxPassengerCount;
		mTravelCheck = 5;

		return *this;
	}
}