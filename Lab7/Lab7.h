#pragma once

#include <iostream>
#include <vector>
#include <map>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		unsigned int mapSize = 0;

		if (keys.size() > values.size())
		{
			mapSize = keys.size();
		}
		else if (keys.size() < values.size())
		{
			mapSize = values.size();
		}
		else
		{
			mapSize = keys.size();
		}

		std::map<K, V> m;

		for (unsigned int length = 0; length < mapSize; length++)
		{
			m.insert(std::pair<K, V>(keys[length], values[length]));
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;

		v.reserve(m.size());

		typename std::map<K, V>::const_iterator iter;

		for (iter = m.begin(); iter != m.end(); iter++)
		{
			v.push_back(iter->first);
		}

		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;

		v.reserve(m.size());

		typename std::map<K, V>::const_iterator iter;

		for (iter = m.begin(); iter != m.end(); iter++)
		{
			v.push_back(iter->second);
		}

		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;

		rv.reserve(v.size());

		for (int length = v.size() - 1; length > -1; length--)
		{
			rv.push_back(v[length]);
		}
		
		return rv;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		unsigned int combinedSize = v1.size() + v2.size();
		bool bCheck = false;

		std::vector<T> combined;

		combined.reserve(combinedSize);

		for (unsigned int length = 0; length < v1.size(); length++)
		{
			combined.push_back(v1[length]);
		}

		for (unsigned int length = 0; length < v2.size(); length++)
		{
			for (unsigned int innerLength = 0; innerLength < combined.size(); innerLength++)
			{
				if (combined[innerLength] == v2[length])
				{
					bCheck = true;
					break;
				}
			}

			if (bCheck == false)
			{
				combined.push_back(v2[length]);
			}
		}


		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;

		typename std::map<K, V>::const_iterator iter;

		for (iter = m1.begin(); iter != m1.end(); iter++)
		{
			combined.insert(std::pair<K, V>(iter->first, iter->second));
		}

		for (iter = m2.begin(); iter != m2.end(); iter++)
		{
			combined.insert(std::pair<K, V>(iter->first, iter->second));
		}

		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		for (unsigned int length = 0; length < v.size(); length++)
		{
			if (length != v.size() - 1)
			{
				os << v[length] << ", ";
			}
			else
			{
				os << v[length];
			}
		}

		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		typename std::map<K, V>::const_iterator iter;

		for (iter = m.begin(); iter != m.end(); iter++)
		{
			os << "{ " << iter->first << ", " << iter->second << " }" << std::endl;
		}

		return os;
	}
}