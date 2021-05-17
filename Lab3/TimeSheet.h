#pragma once
#include <string>


namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		TimeSheet(const TimeSheet& timeSheet);
		~TimeSheet();
		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const std::string& GetName() const;
		TimeSheet& operator=(const TimeSheet& timeSheet);

	private:
		std::string mMyName;
		int* mMyTotalTime = nullptr;
		int mTimeLength = 0;
		int mPosition = 0;

	};
}