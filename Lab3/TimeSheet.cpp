#include "TimeSheet.h"

namespace lab3
{
    TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
    {
        mMyName = name;
        mTimeLength = maxEntries;
        mMyTotalTime = new int[mTimeLength];
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
        if (index < mPosition)
        {
            return mMyTotalTime[index];
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

        for (length = 0; length < mPosition; length++)
        {
            average += mMyTotalTime[length];
        }

        average /= mPosition;
        return average;
    }

    float TimeSheet::GetStandardDeviation() const
    {
        int length;
        float standardDeviation = 0;
        float deviation = 0;

        for (length = 0; length < mPosition; length++)
        {
            deviation = GetAverageTime() - mMyTotalTime[length];
            if (deviation < 0)
            {
                deviation = -deviation;
            }

            standardDeviation += deviation;
        }

        standardDeviation /= mPosition;

        return standardDeviation;
    }

    const std::string& TimeSheet::GetName() const
    {
        return mMyName;
    }
}