#pragma once

#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		Motorcycle(Motorcycle& motorCycle);
		~Motorcycle();

		virtual unsigned int GetDriveSpeed() const;
		Motorcycle& operator=(Motorcycle& motorCycle);

	};
}