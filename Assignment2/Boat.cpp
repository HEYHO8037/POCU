#include "Boat.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		:Vehicle(maxPassengersCount)
	{
		mTravelCheck = 2;
	}
	
	Boat::Boat(Boat& boat)
		: Vehicle(boat)
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
		double weight = GetTotalPassengerWeight();
		double sailSpeed = fmax(800 - (10 * weight), 20);
		sailSpeed += 0.5;

		return static_cast<unsigned int>(sailSpeed);
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
		if (this != &boat)
		{
			DeletePerson();

			mMaxPassengerCount = boat.mMaxPassengerCount;
			mTravelCheck = 2;
			mCount = boat.mCount;
			mPerson = new const Person * [mMaxPassengerCount];

			for (int length = 0; length < mCount; length++)
			{
				AddPassenger(boat.mPerson[length]);
			}

			boat.ChangeArrayNullptr();
			boat.mCount = 0;
		}

		return *this;

	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		unsigned int passengers = plane.GetMaxPassengersCount() + GetMaxPassengersCount();
		unsigned int planePassengers = plane.GetPassengersCount();

		Boatplane bp(passengers);

		for (unsigned int length = 0; length < mCount; length++)
		{
			bp.AddPassenger(mPerson[length]);
		}

		for (unsigned int length = 0; length < planePassengers; length++)
		{
			bp.AddPassenger(plane.GetPassenger(length));
		}

		ChangeArrayNullptr();
		plane.ChangeArrayNullptr();
		
		return bp;
	}
}