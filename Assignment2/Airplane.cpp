#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"

namespace assignment2
{
	Airplane::Airplane()
		: Vehicle()
	{
		mTravelCheck = 4;
	}

	Airplane::Airplane(const Airplane& airPlane)
		: Vehicle(airPlane)
	{
		mTravelCheck = 4;
	}

	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
		mTravelCheck = 4;
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
		if (mTravelCheck == 4)
		{
			mTravelCheck--;
			return GetMaxSpeed();
		}
		else
		{
			mTravelCheck--;
			if (mTravelCheck == 0)
			{
				mTravelCheck = 4;
			}
			return 0;
		}
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		double totalWeight = GetTotalPassengerWeight();
		double totalSpeed = 0;

		totalSpeed = 200 * exp((-totalWeight + 800) / 500);
		totalSpeed += 0.5;
		
		return static_cast<unsigned int>(totalSpeed);
	}

	void Airplane::ResetTravelCheck()
	{
		mTravelCheck = 4;
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		double totalWeight = GetTotalPassengerWeight();
		double totalSpeed = 0;

		totalSpeed = 4 * exp((-totalWeight + 400) / 70);
		totalSpeed = round(totalSpeed);

		return static_cast<unsigned int>(totalSpeed);
	}

	Boatplane Airplane::operator+(Boat& boat)
	{	
		unsigned int passengers = boat.GetMaxPassengersCount() + GetMaxPassengersCount();
		unsigned int boatPassengers = boat.GetPassengersCount();
		
		Boatplane bp(passengers);
		
		for (unsigned int length = 0; length < mCount; length++)
		{
			bp.AddPassenger(mPerson[length]);
		}

		for (unsigned int length = 0; length < boatPassengers; length++)
		{
			bp.AddPassenger(boat.GetPassenger(length));
		}

		ChangeArrayNullptr();
		boat.ChangeArrayNullptr();

		return bp;
	}

	Airplane& Airplane::operator=(const Airplane& airPlane)
	{
		if (this != &airPlane)
		{
			deletePerson();

			mMaxPassengerCount = airPlane.mMaxPassengerCount;
			mCount = airPlane.mCount;
			mTravelCheck = 3;
			mTravelTotalSpeed = airPlane.mTravelTotalSpeed;

			if (mMaxPassengerCount != 0)
			{
				mPerson = new Person * [mMaxPassengerCount];

				for (unsigned int length = 0; length < mCount; length++)
				{
					mPerson[length] = new Person(airPlane.mPerson[length]->GetName().c_str(), airPlane.mPerson[length]->GetWeight());
				}
			}

		}

		return *this;
	}
}