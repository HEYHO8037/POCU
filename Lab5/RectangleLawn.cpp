
#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn()
	{
		mLength = 0;
		mHeight = 0;
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

		return static_cast<unsigned int>(fenceCount+1);
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
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