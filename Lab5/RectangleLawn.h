#pragma once

#include "IFenceable.h"
#include "Lawn.h"

namespace lab5
{
	class RectangleLawn : public Lawn, public IFenceable
	{
	public:
		RectangleLawn();
		RectangleLawn(RectangleLawn& rectangleLawn);
		RectangleLawn(unsigned int length, unsigned int height);
		~RectangleLawn();
		virtual unsigned int GetArea() const;
		virtual unsigned int GetMinimumFencesCount() const;
		virtual unsigned int GetFencePrice(eFenceType fenceType) const;
	private:
		unsigned int mLength;
		unsigned int mHeight;
	};
}