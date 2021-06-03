#pragma once

#include "Person.h"
#include <cmath>

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle();
		Vehicle(Vehicle& vehicle);
		Vehicle(unsigned int maxPassengersCount);
		~Vehicle();

		virtual unsigned int GetMaxSpeed() const = 0;
		virtual unsigned int GetTravelSpeed() = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		int GetTotalPassengerWeight() const;

		Vehicle& operator=(Vehicle& vehicle);
		void ChangeArrayNullptr();

	protected:
		unsigned int mCount;
		unsigned int mMaxPassengerCount;
		const Person* mPerson[100] = { nullptr };
	};
}