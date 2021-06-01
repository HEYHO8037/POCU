#pragma once

#include "Vehicle.h"
#include "IDivable.h"
#include "ISailable.h"

namespace assignment2
{
	class UBoat : public Vehicle, public IDivable, public ISailable
	{
	public:
		UBoat();
		UBoat(UBoat& uBoat);
		~UBoat();

		virtual unsigned int GetDiveSpeed() const;
		virtual unsigned int GetSailSpeed() const;

		UBoat& operator=(UBoat& uBoat);
	};
}