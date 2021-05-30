#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
	{
		mMaxPassengerCount = maxPassengersCount;
	}

	Boatplane::~Boatplane()
	{

	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		return 150 * static_cast<unsigned int>(exp((-GetTotalPassengerWeight() + 500) / 300));
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

	unsigned int Boatplane::GetSailSpeed() const
	{
		return static_cast<unsigned int>(fmax(800 - (1.7 * GetTotalPassengerWeight()), 20));
	}
}