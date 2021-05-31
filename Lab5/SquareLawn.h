#pragma once

#include "RectangleLawn.h"

namespace lab5
{
	class SquareLawn : public RectangleLawn
	{

	public:
		SquareLawn();
		SquareLawn(SquareLawn& squareLawn);
		SquareLawn(unsigned int length);
		~SquareLawn();
		virtual unsigned int GetArea() const;
		virtual unsigned int GetMinimumFencesCount() const;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const;
	private:
		unsigned int mLength;
	};
}