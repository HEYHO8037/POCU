#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mCount(0)
	{
	}

	PolyLine::PolyLine(const PolyLine& other)
	{
		mCount = other.mCount;

		for (int length = 0; length < mCount; length++)
		{
			mPoint[length] = new Point(other.mPoint[length]->GetX(), other.mPoint[length]->GetY());
		}
	}

	PolyLine::~PolyLine()
	{
		for (int length = 0; length < mCount; length++)
		{
			if (mPoint[length] == nullptr)
			{
				continue;
			}
			else
			{
				delete mPoint[length];
				mPoint[length] = nullptr;
			}
		}

	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mCount >= 10)
		{
			return false;
		}
		else
		{
			mPoint[mCount] = new Point(x, y);
			mCount++;
			return true;
		}
	}

	bool PolyLine::AddPoint(const Point* point)
	{

		if (mCount >= 10 || point == nullptr)
		{
			return false;
		}
		else
		{
			mPoint[mCount] = point;
			mCount++;
			return true;
		}
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mCount)
		{
			return false;
		}
		else
		{
			delete mPoint[i];

			for (int length = i; length < mCount; length++)
			{
				if (length == mCount - 1)
				{
					mPoint[length] = 0;
				}
				else
				{
					mPoint[length] = mPoint[length + 1];
				}
			}
			
			mCount--;
			return true;
		}
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		float minimum[2] = { 0 };
		float maximum[2] = { 0 };

		if (mCount == 0)
		{
			return false;
		}

		for (int length = 0; length < mCount; length++)
		{
			if (length == 0)
			{
				minimum[0] = mPoint[length]->GetX();
				minimum[1] = mPoint[length]->GetY();
				maximum[0] = mPoint[length]->GetX();
				maximum[1] = mPoint[length]->GetY();
			}
			else
			{
				maximum[0] = (mPoint[length]->GetX() > maximum[0]) ? mPoint[length]->GetX() : maximum[0];
				maximum[1] = (mPoint[length]->GetY() > maximum[1]) ? mPoint[length]->GetY() : maximum[1];
				minimum[0] = (mPoint[length]->GetX() < minimum[0]) ? mPoint[length]->GetX() : minimum[0];
				minimum[1] = (mPoint[length]->GetY() < minimum[1]) ? mPoint[length]->GetY() : minimum[1];
			}
		}

		*outMin = Point(minimum[0], minimum[1]);
		*outMax = Point(maximum[0], maximum[1]);

		return true;
	}

	PolyLine& PolyLine::operator=(const PolyLine& other)
	{
		mCount = other.mCount;

		for (int length = 0; length < mCount; length++)
		{
			mPoint[length] = new Point(other.mPoint[length]->GetX(), other.mPoint[length]->GetY());
		}

		return *this;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i < mCount)
		{
			return mPoint[i];
		}
		else
		{
			return nullptr;
		}
	}
}