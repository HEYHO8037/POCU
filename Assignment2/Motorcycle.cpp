#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
	{
		mMaxPassengerCount = 2;
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		return static_cast<unsigned int>(fmax((-pow((GetTotalPassengerWeight() / 15), 3) + 2 * GetTotalPassengerWeight() + 400), 0));
	}
}