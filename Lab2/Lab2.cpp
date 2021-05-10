#include "Lab2.h"

using namespace std;

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		int number;

		string nonNumberTrash;

		out << "         out" << "        dec" << "      hex" << endl;
		out << "------------ " << "---------- " << "--------" << endl;

		while (!in.eof())
		{
			in >> number;

			if (in.fail())
			{
				in.clear();
				in >> nonNumberTrash;
			}
			else
			{
				out << std::setfill(' ') << setw(12) << oct << right << number;
				out << std::setfill(' ') << setw(11) << dec << right << number;
				out << std::setfill(' ') << setw(9) << uppercase << hex << right << number << endl;
				continue;
			}
		}
	}


	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float saveMaxNumber = 0.0f;
		float number;

		string nonNumberTrash;

		while (!in.eof())
		{
			in >> number;

			if (in.fail())
			{
				in.clear();
				in >> nonNumberTrash;
			}
			else
			{
				if (saveMaxNumber == 0 || saveMaxNumber < number)
				{
					saveMaxNumber = number;
				}

				out << fixed;
				out.precision(3);
				out << setfill(' ') << setw(5) << "" << setw(15) << internal << showpos << number << endl;
				continue;
			}
		}

		out << fixed;
		out.precision(3);
		out << "max: " << setw(15) << internal << showpos << saveMaxNumber << endl;

	}
}