
#include "CircleLawn.h"

namespace lab5
{
	CircleLawn::CircleLawn()
	{
		mHalfLength = 0;
	}

	CircleLawn::CircleLawn(unsigned int halfLength)
	{
		mHalfLength = halfLength;
	}

	CircleLawn::~CircleLawn()
	{

	}

	unsigned int CircleLawn::GetArea() const
	{
		float area = mHalfLength * mHalfLength * mPi;

		area += 0.5f;

		return static_cast<unsigned int>(area);
	}

	unsigned int CircleLawn::GetMinimumFencesCount() const
	{
		float fenceCount = 2.0f * mHalfLength * mPi;
		fenceCount /= 0.25f;

		if (fenceCount == static_cast<unsigned int>(fenceCount))
		{
			return static_cast<unsigned int>(fenceCount);
		}

		return static_cast<unsigned int>(fenceCount + 1);

	}

	unsigned int CircleLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned int fencePrice = 0;

		switch (fenceType)
		{
		case 0:
			fencePrice = GetMinimumFencesCount() * 1.5;
			break;

		case 1:
			fencePrice = GetMinimumFencesCount() * 1.5;
			break;

		}

		return fencePrice;
	}
}