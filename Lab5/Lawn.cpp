#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn()
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		float grassPrice = 0;

		switch (grassType)
		{
		case 0:
			grassPrice = GetArea() * 8;
			break;
		case 1:
			grassPrice = GetArea() * 5;
			break;
		case 2:
			grassPrice = GetArea() * 3;
			break;
		case 3:
			grassPrice = GetArea() * 2.5;
			break;
		case 4:
			grassPrice = GetArea() * 4.5;
			break;
		}

		return static_cast<unsigned int>(ceil(grassPrice));
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		float rollCount = GetArea() / 0.3f;

		return static_cast<unsigned int>(ceil(rollCount));
	}
}