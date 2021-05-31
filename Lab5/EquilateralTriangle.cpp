
#include "EquilateralTriangleLawn.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn()
	{
		mLength = 0;
	}

	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int length)
	{
		mLength = length;
	}

	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{

	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		return  (sqrt(3) / 4) * (mLength * mLength) + 0.5f;
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		float fenceCount = (mLength * 3) / 0.25f;

		if (fenceCount == static_cast<unsigned int>(fenceCount))
		{
			return static_cast<unsigned int>(fenceCount);
		}

		return static_cast<unsigned int>(fenceCount + 1);
	}

	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned int fencePrice = 0;

		switch (fenceType)
		{
		case 0:
			fencePrice = GetMinimumFencesCount() * 1.5;
			break;

		case 1:
			fencePrice = GetMinimumFencesCount() * 1.75;
			break;

		}

		return fencePrice;
	}
}