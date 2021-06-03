#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Airplane::Airplane()
		: Vehicle()
	{
		mTravelCheck = 3;
	}

	Airplane::Airplane(Airplane& airPlane)
		: Vehicle(airPlane)
	{
		mTravelCheck = 3;
	}

	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		mTravelCheck = 3;
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

	unsigned int Airplane::GetTravelSpeed()
	{
		if (mTravelCheck == 3)
		{
			mTravelCheck--;
			return GetMaxSpeed();
		}
		else
		{
			mTravelCheck--;
			if (mTravelCheck == 0)
			{
				mTravelCheck = 3;
			}
			return 0;
		}
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		double totalWeight = GetTotalPassengerWeight();
		int totalSpeed = 0;

		totalSpeed = 200 * exp((-totalWeight + 800) / 500);
		totalSpeed += 0.5;
		
		return static_cast<unsigned int>(totalSpeed);
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		double totalWeight = GetTotalPassengerWeight();
		double totalSpeed = 0;

		totalSpeed = 4 * exp((-totalWeight + 400) / 70);
		totalSpeed += 0.5;

		return static_cast<unsigned int>(totalSpeed);
	}

	Boatplane Airplane::operator+(Boat& boat)
	{	
		unsigned int passengers = boat.GetMaxPassengersCount() + GetMaxPassengersCount();
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

	Airplane& Airplane::operator=(Airplane& airPlane)
	{
		for (int length = 0; length < mCount; length++)
		{
			if (mPerson[length] != nullptr)
			{
				delete mPerson[length];
			}
			else
			{
				continue;
			}
		}

		mMaxPassengerCount = airPlane.mMaxPassengerCount;
		mCount = airPlane.mCount;
		mTravelCheck = 3;
		mPerson = new Person * [mMaxPassengerCount];
		
		for (int length = 0; length < mCount; length++)
		{
			AddPassenger(airPlane.mPerson[length]);
		}

		airPlane.ChangeArrayNullptr();
		airPlane.mCount = 0;

		return *this;
	}
}