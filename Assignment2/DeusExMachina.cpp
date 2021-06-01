#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina::DeusExMachina()
	{
		mCountVehicle = 0;
		isTravel = false;
	}

	DeusExMachina::~DeusExMachina()
	{
		delete mDeusExMachina;
	}

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mDeusExMachina == nullptr)
		{
			mDeusExMachina = new DeusExMachina();
		}
		return mDeusExMachina;
	}

	void DeusExMachina::Travel() const
	{
		isTravel = true;

		for (unsigned int length = 0; length < mCountVehicle; length++)
		{
			mCountSpeed[length] = mVehicle[length]->GetTravelSpeed();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mCountVehicle < 10 || vehicle != nullptr)
		{
			mVehicle[mCountVehicle] = vehicle;
			mCountVehicle++;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i > mCountVehicle)
		{
			return false;
		}
		else
		{
			delete mVehicle[i];

			for (unsigned int length = i; length < mCountVehicle; length++)
			{
				if (length == mCountVehicle - 1)
				{
					mVehicle[length] = nullptr;
				}
				else
				{
					mVehicle[length] = mVehicle[length + 1];
				}
			}
		}
		return false;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		unsigned int topSpeed = 0;

		if (mCountVehicle == 0)
		{
			return NULL;
		}
		else if (isTravel == false && mCountVehicle != 0)
		{
			return mVehicle[0];
		}
		else
		{
			for (unsigned int length = 0; length < mCountVehicle; length++)
			{
				if (topSpeed > mCountSpeed[length])
				{
					continue;
				}
				else
				{
					topSpeed = mCountSpeed[length];
				}
			}

			for (unsigned int length = 0; length < mCountVehicle; length++)
			{
				if (topSpeed == mCountSpeed[length])
				{
					return mVehicle[length];
				}
			}
		}

	}
}