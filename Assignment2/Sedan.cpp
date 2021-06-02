#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
	{
		mTrailer = nullptr;
		mTravelCheck = 6;
	}

	Sedan::Sedan(Sedan& sedan)
		: Vehicle(sedan)
	{
		mTrailer = sedan.mTrailer;
		mTravelCheck = 6;
	}

	Sedan::~Sedan()
	{
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (trailer == nullptr || mTrailer != nullptr)
		{
			return false;
		}
		else
		{
			mTrailer = trailer;
			return true;
		}
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailer == nullptr)
		{
			return false;
		}
		else
		{
			mTrailer = nullptr;
			return true;
		}
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		int weight = GetTotalPassengerWeight() + mTrailer->GetWeight();

		if (weight <= 80)
		{
			return 450;
		}
		else if (160 >= weight && weight > 80)
		{
			return 458;
		}
		else if (260 >= weight && weight > 160)
		{
			return 400;
		}
		else if (350 >= weight && weight > 260)
		{
			return 380;
		}
		else if (weight > 350)
		{
			return 300;
		}
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Sedan::GetTravelSpeed()
	{
		if (mTravelCheck == 1 && mTrailer == nullptr)
		{
			mTravelCheck = 6;
			return 0;
		}
		else if (mTravelCheck == 1 && mTrailer != nullptr)
		{
			mTravelCheck--;
			return 0;
		}
		else if (mTravelCheck == 0 && mTrailer != nullptr)
		{
			mTravelCheck = 6;
			return 0;
		}
		else
		{
			mTravelCheck--;
			return GetMaxSpeed();
		}
	}


	Sedan& Sedan::operator=(Sedan& sedan)
	{
		mTrailer = sedan.mTrailer;
		mMaxPassengerCount = 4;
		mTravelCheck = 6;

		return *this;
	}
}