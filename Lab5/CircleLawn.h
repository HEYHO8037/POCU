#pragma once

#include "IFenceable.h"
#include "Lawn.h"
#include <cmath>

namespace lab5
{
	class CircleLawn : public Lawn, public IFenceable
	{
	public:
		CircleLawn();
		CircleLawn(unsigned int halfLength);
		~CircleLawn();
		virtual unsigned int GetArea() const;
		virtual unsigned int GetMinimumFencesCount() const;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const;
	private:
		unsigned int mHalfLength;
		float mPi = 3.14f;
	};
}