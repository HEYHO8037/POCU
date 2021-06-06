#pragma once

#include "Vehicle.h"
#include "IDrivable.h"
#include "Trailer.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		Sedan(const Sedan& sedan);
		~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

		virtual unsigned int GetDriveSpeed() const;
		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetTravelSpeed();
		virtual void ResetTravelCheck();

		Sedan& operator=(const Sedan& sedan);

	private:
		const Trailer* mTrailer;
	};
}