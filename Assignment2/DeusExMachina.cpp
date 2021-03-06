#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::mDeusExMachina = nullptr;
	unsigned int DeusExMachina::mCountVehicle = 0;
	bool DeusExMachina::mbTravel = false;

	DeusExMachina::DeusExMachina()
	{
	}

	DeusExMachina::~DeusExMachina()
	{
		for (unsigned int length = 0; length < mCountVehicle; length++)
		{
			if (mVehicle[length] != nullptr)
			{
				delete mVehicle[length];
				mVehicle[length] = nullptr;
			}
			else
			{
				continue;
			}
		}

		mbTravel = false;
		mCountVehicle = 0;
		mDeusExMachina = nullptr;
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
		mbTravel = true;

		for (unsigned int length = 0; length < mCountVehicle; length++)
		{
			mVehicle[length]->GetTravel();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mCountVehicle >= 10 || vehicle == nullptr)
		{
			return false;
		}
		else
		{
			mVehicle[mCountVehicle] = vehicle;
			mVehicle[mCountVehicle]->ResetTravelCheck();
			mCountVehicle++;
			return true;
		}
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mCountVehicle)
		{
			return false;
		}
		else
		{
			delete mVehicle[i];
			mVehicle[i] = nullptr;

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
		unsigned int topLength = 0;

		if (mCountVehicle == 0)
		{
			return NULL;
		}
		else if (mbTravel == false && mCountVehicle != 0)
		{
			return mVehicle[0];
		}
		else
		{
			for (unsigned int length = 0; length < mCountVehicle; length++)
			{
				if (topSpeed >= mVehicle[length]->GetTravelTotalSpeed())
				{
					continue;
				}
				else
				{
					topSpeed = mVehicle[length]->GetTravelTotalSpeed();
					topLength = length;
				}
			}

			return mVehicle[topLength];
		}

	}
}