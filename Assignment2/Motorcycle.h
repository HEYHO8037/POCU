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
		virtual unsigned int GetTravelSpeed() const;
		virtual unsigned int GetMaxSpeed() const;

		Motorcycle& operator=(Motorcycle& motorCycle);
	private:
		static unsigned int mTravelCheck;

	};
}