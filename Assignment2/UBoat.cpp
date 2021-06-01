#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
	{
		mMaxPassengerCount = 50;
	}

	UBoat::UBoat(UBoat& uBoat)
	{
		mMaxPassengerCount = uBoat.mMaxPassengerCount;
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

	UBoat& UBoat::operator=(UBoat& uBoat)
	{
		mMaxPassengerCount = uBoat.mMaxPassengerCount;
	}
}