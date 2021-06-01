
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
		double area = mHalfLength * mHalfLength * mPi;

		area += 0.5f;

		return static_cast<unsigned int>(area);
	}
}