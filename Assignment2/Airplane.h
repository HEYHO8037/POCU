#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "IFlyable.h"
#include "IDrivable.h"
#include "Boat.h"

namespace assignment2
{
	class Boat;

	class Airplane  : public Vehicle, public IFlyable, public IDrivable
	{
	public:
		Airplane();
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		virtual unsigned int GetFlySpeed() const;
		virtual unsigned int GetDriveSpeed() const;
		virtual unsigned int GetMaxSpeed() const;
		Boatplane operator+(Boat& boat);
	};
}