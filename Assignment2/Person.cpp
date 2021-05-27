#include "Person.h"

namespace assignment2
{
	Person::Person()
	{
		mName = nullptr;
		mPersonWeight = 0;
	}

	Person::Person(const char* name, unsigned int weight)
	{
		mName = name;
		mPersonWeight = weight;
	}

	Person::~Person()
	{

	}

	const std::string& Person::GetName() const
	{
		return mName;
	}

	unsigned int Person::GetWeight() const
	{
		return mPersonWeight;
	}
}