#include "Lab2.h"

using namespace std;

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		int number;

		char nonNumberTrash;

		out << "         oct" << "        dec" << "      hex" << endl;
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
			}
		}
	}


	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float saveMaxNumber = 0.0f;
		int count = 0;
		float number;

		string nonNumberTrash;

		while (!in.eof())
		{
			in >> number;
			count++;

			if (in.fail())
			{
				in.clear();
				in >> nonNumberTrash;
			}
			else
			{
				if (count == 1)
				{
					saveMaxNumber = number;
				}
				else if (count != 1 && saveMaxNumber - number <= 0)
				{
					saveMaxNumber = number;
				}
				

				out << fixed;
				out.precision(3);
				out << setfill(' ') << setw(5) << "" << setw(15) << internal << showpos << number << endl;
			}
		}

		out << fixed;
		out.precision(3);
		out << "max: " << setw(15) << internal << showpos << saveMaxNumber << endl;

	}
}