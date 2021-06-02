#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		:Vehicle(maxPassengersCount)
	{
		mTravelCheck = 2;
	}

	Boat::~Boat()
	{

	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	unsigned int Boat::GetSailSpeed() const
	{
		return static_cast<unsigned int>(fmax(800 - (10 * GetTotalPassengerWeight()), 20));
	}

	unsigned int Boat::GetTravelSpeed()
	{
		if (mTravelCheck == 0)
		{
			mTravelCheck = 2;
			return 0;
		}
		else
		{
			mTravelCheck--;
			return GetMaxSpeed();
		}
	}

	Boat& Boat::operator=(Boat& boat)
	{
		mMaxPassengerCount = boat.mMaxPassengerCount;
		mTravelCheck = 2;

		return *this;
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		unsigned int passengers = plane.GetPassengersCount() + GetPassengersCount();
		unsigned int planePassengers = plane.GetPassengersCount();

		Boatplane bp(passengers);

		for (int length = 0; length < mCount; length++)
		{
			bp.AddPassenger(mPerson[length]);
		}

		for (int length = 0; length < planePassengers; length++)
		{
			bp.AddPassenger(plane.GetPassenger(length));
		}

		ChangeArrayNullptr();
		plane.ChangeArrayNullptr();
		
		return bp;
	}
}