#include "TimeSheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
	{
		int length;
		mMyName = name;
		mTimeLength = maxEntries;
		mMyTotalTime = new int[mTimeLength];

		for (length = 0; length < mTimeLength; length++)
		{
			mMyTotalTime[length] = 0;
		}

	}

	TimeSheet::TimeSheet(const TimeSheet& timeSheet)
	{
		int length;

		mMyName = timeSheet.mMyName;
		mTimeLength = timeSheet.mTimeLength;
		mPosition = timeSheet.mPosition;

		mMyTotalTime = new int[mTimeLength];

		if (mPosition != 0)
		{
			for (length = 0; length < mTimeLength; length++)
			{
				mMyTotalTime[length] = timeSheet.mMyTotalTime[length];
			}
		}
	}


	TimeSheet::~TimeSheet()
	{
		delete[] mMyTotalTime;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours > 0 && timeInHours < 11 && mPosition < mTimeLength)
		{
			mMyTotalTime[mPosition] = timeInHours;
			mPosition++;
		}
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		int changeIndex = index;

		if (changeIndex < mPosition)
		{
			return mMyTotalTime[changeIndex];
		}
		else
		{
			return -1;
		}

	}

	int TimeSheet::GetTotalTime() const
	{
		int length;
		int total = 0;

		for (length = 0; length < mPosition; length++)
		{
			total += mMyTotalTime[length];
		}


		return total;
	}

	float TimeSheet::GetAverageTime() const
	{
		int length;
		float average = 0.0f;

		if (mPosition != 0)
		{

			for (length = 0; length < mPosition; length++)
			{
				average += mMyTotalTime[length];
			}
			average /= mPosition;

			return average;
		}
		else
		{
			return 0.0f;
		}

	}

	float TimeSheet::GetStandardDeviation() const
	{
		int length;

		float standardDeviation = 0;
		float deviation = 0;
		float sqrt = 2.0f;

		if (mPosition != 0)
		{
			for (length = 0; length < mPosition; length++)
			{
				deviation = GetAverageTime() - mMyTotalTime[length];
				deviation *= deviation;

				standardDeviation += deviation;
			}

			standardDeviation /= mPosition;

			for (length = 0; length < 10; length++)
			{
				sqrt = (sqrt + (standardDeviation / sqrt)) / 2;
			}

			return sqrt;
		}
		else
		{
			return 0.0f;
		}
	}

	const std::string& TimeSheet::GetName() const
	{
		return mMyName;
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& timeSheet)
	{
		int length;

		mMyName = timeSheet.mMyName;
		mTimeLength = timeSheet.mTimeLength;
		mPosition = timeSheet.mPosition;

		mMyTotalTime = new int[mTimeLength];

		if (mPosition != 0)
		{
			for (length = 0; length < mTimeLength; length++)
			{
				mMyTotalTime[length] = timeSheet.mMyTotalTime[length];
			}
		}
		return *this;
	}
}