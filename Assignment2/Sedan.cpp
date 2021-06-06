#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4), mTrailer(nullptr), mTravelCheck(6)
	{
	}

	Sedan::Sedan(const Sedan& sedan)
		: Vehicle(sedan), mTravelCheck(6)
	{
		if (sedan.mTrailer != nullptr)
		{
			mTrailer = new Trailer(sedan.mTrailer->GetWeight());
		}
		else
		{
			mTrailer = nullptr;
		}
	}


	Sedan::~Sedan()
	{
		if (mTrailer != nullptr)
		{
			delete mTrailer;
		}
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
			delete mTrailer;
			mTrailer = nullptr;
			return true;
		}
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		int weight = 0;

		if (mTrailer != nullptr)
		{
			weight = GetTotalPassengerWeight() + static_cast<int>(mTrailer->GetWeight());
		}
		else
		{
			weight = GetTotalPassengerWeight();
		}

		if (weight <= 80)
		{
			return 480;
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


	Sedan& Sedan::operator=(const Sedan& sedan)
	{
		if (this != &sedan)
		{
			DeletePerson();

			if (mTrailer != nullptr)
			{
				delete mTrailer;
				mTrailer = nullptr;
			}

			mTrailer = sedan.mTrailer;
			mMaxPassengerCount = sedan.mMaxPassengerCount;
			mTravelCheck = 6;
			mCount = sedan.mCount;
			
			if (mMaxPassengerCount != 0)
			{
				mPerson = new Person * [mMaxPassengerCount];

				for (unsigned int length = 0; length < mCount; length++)
				{
					mPerson[length] = new Person(sedan.mPerson[length]->GetName().c_str(), sedan.mPerson[length]->GetWeight());
				}
			}

			if (sedan.mTrailer != nullptr)
			{
				mTrailer = new Trailer(sedan.mTrailer->GetWeight());
			}
			else
			{
				mTrailer = nullptr;
			}

		}

		return *this;
	}
}