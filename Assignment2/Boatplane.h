#pragma once

#include "Vehicle.h"
#include "IFlyable.h"
#include "ISailable.h"

namespace assignment2
{
	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		Boatplane(Boatplane& boatPlane);
		~Boatplane();

		virtual unsigned int GetFlySpeed() const;
		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetSailSpeed() const;
		virtual unsigned int GetTravelSpeed();

		Boatplane& operator=(Boatplane& boatPlane);
	private:
		unsigned int mTravelCheck;
		
	};
}