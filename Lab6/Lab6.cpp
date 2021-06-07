#include "Lab6.h"

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int sum = 0;

		for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++)
		{
			sum += *iter;
		}

		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		return 0;
	}

	int Max(const std::vector<int>& v)
	{
		return 0;
	}

	float Average(const std::vector<int>& v)
	{
		return 0.0f;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		return 0;
	}

	void SortDescending(std::vector<int>& v)
	{

	}

}