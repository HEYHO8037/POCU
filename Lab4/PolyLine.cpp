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
			mPoint[length] = other.mPoint[length];
		}
	}

	PolyLine::~PolyLine()
	{
		for (int length = 0; length < mCount; length++)
		{
			if (mPpoint[length] == nullptr)
			{
				continue;
			}
			else
			{
				delete mPpoint[length];
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
			mPoint[mCount] = Point(x, y);
			mCount++;
			return true;
		}
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mCount >= 10)
		{
			return false;
		}
		else
		{
			mPoint[mCount] = Point(*point);
			mPpoint[mCount] = point;
			mCount++;
			return true;
		}
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		Point* savePoint;;
		if (i >= mCount)
		{
			return false;
		}
		else
		{
			if (mPpoint[i] != nullptr && mPoint[i].GetX() == mPpoint[i]->GetX())
			{
				delete mPpoint[i];
				mPpoint[i] = nullptr;
			}

			for (int length = i; length < mCount-1; length++)
			{
				mPoint[length] = mPoint[length + 1];
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
				minimum[0] = mPoint[length].GetX();
				minimum[1] = mPoint[length].GetY();
				maximum[0] = mPoint[length].GetX();
				maximum[1] = mPoint[length].GetY();
			}
			else
			{
				maximum[0] = (mPoint[length].GetX() > maximum[0]) ? mPoint[length].GetX() : maximum[0];
				maximum[1] = (mPoint[length].GetY() > maximum[1]) ? mPoint[length].GetY() : maximum[1];
				minimum[0] = (mPoint[length].GetX() < minimum[0]) ? mPoint[length].GetX() : minimum[0];
				minimum[1] = (mPoint[length].GetY() < minimum[1]) ? mPoint[length].GetY() : minimum[1];
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
			mPoint[length] = other.mPoint[length];
		}

		return *this;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i < mCount)
		{
			return &mPoint[i];
		}
		else
		{
			return nullptr;
		}
	}
}