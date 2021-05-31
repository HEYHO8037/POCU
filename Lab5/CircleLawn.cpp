
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
		return 0;
	}

	unsigned int CircleLawn::GetFencePrice(eFenceType fenceType) const
	{
		return 0;
	}
}