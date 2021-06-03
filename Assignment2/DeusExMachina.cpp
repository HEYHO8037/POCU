#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::mDeusExMachina = nullptr;
	unsigned int DeusExMachina::mCountSpeed[10] = { 0 };
	unsigned int DeusExMachina::mCountVehicle = 0;
	bool DeusExMachina::isTravel = false;

	DeusExMachina::DeusExMachina()
	{
	}

	DeusExMachina::~DeusExMachina()
	{
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
			mCountSpeed[length] += mVehicle[length]->GetTravelSpeed();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mCountVehicle < 10 && vehicle != nullptr)
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

			mCountVehicle--;
		}
		return true;
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