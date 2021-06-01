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
		Sedan(Sedan& sedan);
		~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

		virtual unsigned int GetDriveSpeed() const;

		Sedan& operator=(Sedan& sedan);

	private:
		const Trailer* mTrailer;

	};
}