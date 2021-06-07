#pragma once

#include "Vehicle.h"
#include "Airplane.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		~DeusExMachina();
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;

	private:
		DeusExMachina();
		static DeusExMachina* mDeusExMachina;
		Vehicle* mVehicle[10] = { nullptr };
		static unsigned int mCountVehicle;
		static bool mbTravel;
	};

}