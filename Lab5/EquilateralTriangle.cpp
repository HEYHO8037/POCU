
#include "EquilateralTriangleLawn.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn()
	{
		mLength = 0;
	}

	EquilateralTriangleLawn::EquilateralTriangleLawn(EquilateralTriangleLawn& equilateralTriangleLawn)
	{
		mLength = equilateralTriangleLawn.mLength;
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
		return  static_cast<unsigned int>((sqrt(3) / 4) * (mLength * mLength) + 0.5f);
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
		float fencePrice = 0;

		switch (fenceType)
		{
		case 0:
			fencePrice = static_cast<float>(GetMinimumFencesCount()) * 1.5f;
			break;

		case 1:
			fencePrice = static_cast<float>(GetMinimumFencesCount()) * 1.75f;
			break;

		}

		return static_cast<unsigned int>(fencePrice);
	}
}