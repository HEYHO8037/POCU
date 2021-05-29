#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Airplane::Airplane()
	{
		mMaxPassengerCount = 0;
	}

	Airplane::Airplane(unsigned int maxPassengersCount)
	{
		mMaxPassengerCount = maxPassengersCount;
	}

	Airplane::~Airplane()
	{

	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		if (GetFlySpeed() > GetDriveSpeed())
		{
			return GetFlySpeed();
		}
		else
		{
			return GetDriveSpeed();
		}
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		int totalWeight = GetTotalPassengerWeight();
		int totalSpeed = 0;

		totalSpeed = 200 * exp((-totalWeight + 800) / 500);
		
		return totalSpeed;
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		int totalWeight = GetTotalPassengerWeight();
		int totalSpeed = 0;

		totalSpeed = 4 * exp((-totalWeight + 400) / 70);
		return 0;
	}

	Boatplane Airplane::operator+(Boat& boat)
	{	
		unsigned int passengers = boat.GetPassengersCount() + GetPassengersCount();
		unsigned int boatPassengers = boat.GetPassengersCount();
		
		Boatplane bp(passengers);
		
		for (int length = 0; length < mCount; length++)
		{
			bp.AddPassenger(mPerson[length]);
		}

		for (int length = 0; length < boatPassengers; length++)
		{
			bp.AddPassenger(boat.GetPassenger(length));
		}

		ChangeArrayNullptr();
		boat.ChangeArrayNullptr();

		return bp;
	}
}