#pragma once

#include "Vehicle.h"
#include "Airplane.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;


	private:
		DeusExMachina();
		~DeusExMachina();
		static DeusExMachina* mDeusExMachina;
		Vehicle** mVehicle = new Vehicle* [10];
		static unsigned int mCountVehicle;
		static unsigned int mCountTravel;
	};

}