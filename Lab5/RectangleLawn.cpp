
#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn()
	{
		mLength = 0;
		mHeight = 0;
	}

	RectangleLawn::RectangleLawn(RectangleLawn& rectangleLawn)
	{
		mLength = rectangleLawn.mLength;
		mHeight = rectangleLawn.mHeight;
	}

	RectangleLawn::RectangleLawn(unsigned int length, unsigned int height)
	{
		mLength = length;
		mHeight = height;
	}

	RectangleLawn::~RectangleLawn()
	{

	}

	unsigned int RectangleLawn::GetArea() const
	{
		return mLength * mHeight;
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		float fenceCount = ((mHeight + mLength) * 2)  / 0.25f;

		if (fenceCount == static_cast<unsigned int>(fenceCount))
		{
			return static_cast<unsigned int>(fenceCount);
		}

		fenceCount += 1;
		return static_cast<unsigned int>(fenceCount);
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
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