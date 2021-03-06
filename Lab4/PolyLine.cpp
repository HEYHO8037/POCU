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
		DeleteMemory();
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
		int getPosition = i;
		if (getPosition >= mCount)
		{
			return false;
		}
		else
		{
			delete mPoint[i];
			mPoint[i] = nullptr;

			for (int length = i; length < mCount; length++)
			{
				if (length == mCount - 1)
				{
					mPoint[length] = nullptr;
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

		if (this == &other)
		{
			return *this;
		}
		else
		{
			DeleteMemory();
			for (int length = 0; length < mCount; length++)
			{
				mPoint[length] = new Point(other.mPoint[length]->GetX(), other.mPoint[length]->GetY());
			}

			return *this;
		}
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		int getPosition = i;

		if (getPosition < mCount)
		{
			return mPoint[i];
		}
		else
		{
			return nullptr;
		}
	}

	void PolyLine::DeleteMemory()
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
}