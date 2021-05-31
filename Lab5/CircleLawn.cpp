
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

	CircleLawn::CircleLawn(CircleLawn& circleLawn)
	{
		mHalfLength = circleLawn.mHalfLength;
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
		float fencePrice = 0;

		switch (fenceType)
		{
		case 0:
			fencePrice = static_cast<float>(GetMinimumFencesCount()) * 1.5;
			break;

		case 1:
			fencePrice = static_cast<float>(GetMinimumFencesCount()) * 1.5;
			break;

		}

		return static_cast<unsigned int>(fencePrice);
	}
}