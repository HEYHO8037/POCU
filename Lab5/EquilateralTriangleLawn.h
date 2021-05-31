#pragma once

#include "IFenceable.h"
#include "Lawn.h"
#include <cmath>

namespace lab5
{
	class EquilateralTriangleLawn : public Lawn, public IFenceable
	{
	public:
		EquilateralTriangleLawn();
		EquilateralTriangleLawn(EquilateralTriangleLawn& equilateralTriangleLawn);
		EquilateralTriangleLawn(unsigned int length);
		~EquilateralTriangleLawn();
		virtual unsigned int GetArea() const;
		virtual unsigned int GetMinimumFencesCount() const;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const;
	private:
		unsigned int mLength;
	};
}