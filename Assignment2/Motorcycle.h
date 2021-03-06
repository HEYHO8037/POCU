#pragma once

#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		Motorcycle(const Motorcycle& motorCycle);
		~Motorcycle();

		virtual unsigned int GetDriveSpeed() const;
		virtual unsigned int GetTravelSpeed();
		virtual unsigned int GetMaxSpeed() const;
		virtual void ResetTravelCheck();


		Motorcycle& operator=(const Motorcycle& motorCycle);
	private:
	};
}