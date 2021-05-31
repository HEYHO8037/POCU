#pragma once

#include "IFenceable.h"
#include "Lawn.h"

namespace lab5
{
	class CircleLawn : public Lawn
	{
	public:
		CircleLawn();
		CircleLawn(CircleLawn& circleLawn);
		CircleLawn(unsigned int halfLength);
		~CircleLawn();
		virtual unsigned int GetArea() const;
	private:
		unsigned int mHalfLength;
		float mPi = 3.14f;
	};
}