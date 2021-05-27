#include "Trailer.h"

namespace assignment2
{
	Trailer::Trailer(unsigned int weight)
	{
		mTrailerWeight = weight;
	}

	Trailer::~Trailer()
	{
	}

	unsigned int Trailer::GetWeight() const
	{
		return mTrailerWeight;
	}
}