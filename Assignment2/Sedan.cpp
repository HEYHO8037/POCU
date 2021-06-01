#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
	{
		mTrailer = nullptr;
		mMaxPassengerCount = 4;
	}

	Sedan::Sedan(Sedan& sedan)
	{
		mTrailer = sedan.mTrailer;
		mMaxPassengerCount = 4;
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
		unsigned int weight = GetTotalPassengerWeight() + mTrailer->GetWeight();

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

	Sedan& Sedan::operator=(Sedan& sedan)
	{
		mTrailer = sedan.mTrailer;
		mMaxPassengerCount = 4;
	}
}