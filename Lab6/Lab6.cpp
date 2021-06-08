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
		int min = INT_MAX;

		if (v.size() == 0)
		{
			return min;
		}
		else
		{
			for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++)
			{
				if (min < *iter)
				{
					continue;
				}
				else
				{
					min = *iter;
				}
			}
			
			return min;
		}
	}

	int Max(const std::vector<int>& v)
	{
		int min = INT_MIN;

		if (v.size() == 0)
		{
			return min;
		}
		else
		{
			for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++)
			{
				if (min > *iter)
				{
					continue;
				}
				else
				{
					min = *iter;
				}
			}

			return min;
		}
	}

	float Average(const std::vector<int>& v)
	{
		float average = 0;

		for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++)
		{
			average += *iter;
		}

		average /= v.size();

		return average;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		int count = 0;
		int saveCount = 0;
		int saveLength = 0;

		if (v.size() == 0)
		{
			return 0;
		}
		else
		{
			for (int totalLength = 0; totalLength < v.size(); totalLength++)
			{
				count = 0;

				for (int length = 0; length < v.size(); length++)
				{
					if (totalLength == length)
					{
						continue;
					}
					else if (v[totalLength] == v[length])
					{
						count++;
					}
				}

				if (count > saveCount)
				{
					saveCount = count;
					saveLength = totalLength;
				}

			}
		}
		return v[saveLength];
	}

	void SortDescending(std::vector<int>& v)
	{
		int save = 0;

		for (int totalLength = 0; totalLength < v.size(); totalLength++)
		{
			for (int length = totalLength; length < v.size(); length++)
			{
				if (v[totalLength] < v[length] && totalLength != length)
				{
					save = v[totalLength];
					v[totalLength] = v[length];
					v[length] = save;
				}
			}
		}
	}

}