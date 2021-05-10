#include "Lab2.h"

namespace lab2
{
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
        int number;
        int count = 0;
        std::string nonNumberTrash;

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
                if (count == 0)
                {
                    out << "         out" << "        dec" << "      hex" << std::endl;
                    out << "------------ " << "---------- " << "--------" << std::endl;
                    count++;
                }

                out << std::setfill(' ') << std::setw(12) << std::oct << std::right << number;
                out << std::setfill(' ') << std::setw(11) << std::dec << std::right << number;
                out << std::setfill(' ') << std::setw(9) << std::hex << std::right << number << std::endl;
                continue;
            }
        }
    }

    void PrintMaxFloat(std::istream& in, std::ostream& out)
    {
        float saveMaxNumber = 0.0f;
        float number;

        std::string nonNumberTrash;

        while (!in.eof())
        {
            in >> number;

            if (in.get() != '.' && in.fail())
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

                out << std::fixed;
                out.precision(3);
                out << std::setfill(' ') << std::setw(5) <<  "" << std::setw(15) << std::internal << std::showpos << number << std::endl;
                continue;
            }
        }

        out << std::fixed;
        out.precision(3);
        out << "max: " << std::setw(15) << std::internal << std::showpos << saveMaxNumber << std::endl;

    }
}