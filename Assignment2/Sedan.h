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

		Sedan& operator=(const Sedan& sedan);

	private:
		const Trailer* mTrailer;
		unsigned int mTravelCheck;
	};
}