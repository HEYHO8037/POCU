#pragma once

#include <string>

namespace assignment2
{
	class Person
	{
	public:
		Person();
		Person(const Person& person);
		Person(const char* name, unsigned int weight);
		~Person();

		const std::string& GetName() const;
		unsigned int GetWeight() const;

		Person& operator=(const Person& person);

	private:
		std::string mName;
		unsigned int mPersonWeight;

	};

}