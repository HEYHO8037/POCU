#pragma once

#include <string>

namespace assignment2
{
	class Person
	{
	public:
		Person();
		Person(Person& person);
		Person(const char* name, unsigned int weight);
		~Person();

		const std::string& GetName() const;
		unsigned int GetWeight() const;

		Person& operator=(Person& person);

	private:
		std::string mName;
		int mPersonWeight;

	};

}