#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
	{
		mMaxPassengerCount = maxPassengersCount;
	}

	Boat::~Boat()
	{

	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return 0;
	}

	unsigned int Boat::GetSailSpeed() const
	{
		return 0;
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane bp(5);
		
		return bp;
	}
}