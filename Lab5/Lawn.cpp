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
		double grassPrice = 0;

		switch (grassType)
		{
		case 0:
			grassPrice = static_cast<double>(GetArea()) * 8.0f;
			break;
		case 1:
			grassPrice = static_cast<double>(GetArea()) * 5.0f;
			break;
		case 2:
			grassPrice = static_cast<double>(GetArea()) * 3.0f;
			break;
		case 3:
			grassPrice = static_cast<double>(GetArea()) * 2.5f;
			break;
		case 4:
			grassPrice = static_cast<double>(GetArea()) * 4.5f;
			break;
		}

		if (grassPrice == static_cast<unsigned int>(grassPrice))
		{
			return static_cast<unsigned int>(grassPrice);
		}

		return static_cast<unsigned int>(grassPrice + 1);
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		double rollCount = GetArea() / 0.3f;

		if (rollCount == static_cast<unsigned int>(rollCount))
		{
			return static_cast<unsigned int>(rollCount);
		}

		return static_cast<unsigned int>(rollCount + 1);
	}
}