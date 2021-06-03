#include "Trailer.h"

namespace assignment2
{
	Trailer::Trailer(unsigned int weight)
	{
		mTrailerWeight = weight;
	}

	Trailer::Trailer(Trailer& trailer)
	{
		mTrailerWeight = trailer.mTrailerWeight;
	}

	Trailer::~Trailer()
	{
	}

	unsigned int Trailer::GetWeight() const
	{
		return mTrailerWeight;
	}

	Trailer& Trailer::operator=(Trailer& trailer)
	{
		if (this != &trailer)
		{
			mTrailerWeight = trailer.mTrailerWeight;
		}

		return *this;
	}
}