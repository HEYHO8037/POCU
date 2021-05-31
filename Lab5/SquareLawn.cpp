
#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn()
	{
		mLength = 0;
	}

	SquareLawn::SquareLawn(unsigned int length)
	{
		mLength = length;
	}

	SquareLawn::~SquareLawn()
	{

	}

	unsigned int SquareLawn::GetArea() const
	{
		return RectangleLawn(mLength, mLength).GetArea();
	}

	unsigned int SquareLawn::GetMinimumFencesCount() const
	{
		return RectangleLawn(mLength, mLength).GetMinimumFencesCount();
	}

	unsigned int SquareLawn::GetFencePrice(eFenceType fenceType) const
	{
		return RectangleLawn(mLength, mLength).GetFencePrice(fenceType);
	}
}