#include "Person.h"

namespace assignment2
{
	Person::Person()
	{
		mName = "";
		mPersonWeight = 0;
	}

	Person::Person(Person& person)
	{
		mName = person.mName;
		mPersonWeight = person.mPersonWeight;
	}

	Person::Person(std::string name, unsigned int weight)
	{
		mName = name;
		mPersonWeight = weight;
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

	Person& Person::operator=(Person& person)
	{
		mName = person.mName;
		mPersonWeight = person.mPersonWeight;

		return *this;
	}
}