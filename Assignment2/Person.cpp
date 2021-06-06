#include "Person.h"

namespace assignment2
{
	Person::Person()
		: mName(""), mPersonWeight(0)
	{
	}

	Person::Person(const Person& person)
		: mName(person.mName), mPersonWeight(person.mPersonWeight)
	{
		
	}

	Person::Person(const char* name, unsigned int weight)
		: mName(name), mPersonWeight(weight)
	{
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

	Person& Person::operator=(const Person& person)
	{
		if (&person != this)
		{
			mName = person.mName;
			mPersonWeight = person.mPersonWeight;
		}

		return *this;
	}
}