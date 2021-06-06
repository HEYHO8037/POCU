#pragma once

#include "Boatplane.h"
#include "Vehicle.h"
#include "ISailable.h"
#include "Airplane.h"


namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		Boat(const Boat& boat);
		~Boat();

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetSailSpeed() const;
		virtual unsigned int GetTravelSpeed();
		virtual void ResetTravelCheck();

		Boatplane operator+(Airplane& plane);
		Boat& operator=(const Boat& boat);
	private:
	};
}