#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina::DeusExMachina()
	{
		mCountTravel = 0;
		mCountVehicle = 0;
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

			for (int length = i; length < mCountVehicle; length++)
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
		return NULL;
	}
}