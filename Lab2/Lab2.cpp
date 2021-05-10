#include "Lab2.h"

namespace lab2
{
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
        int number;
        int count = 0;
        char nonNumberTrash;

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

                out << std::setfill(' ') << std::setw(12) << std::oct << number;
                out << std::setfill(' ') << std::setw(11) << std::dec << number;
                out << std::setfill(' ') << std::setw(9) << std::hex << number << std::endl;
                continue;
            }
        }
    }

    void PrintMaxFloat(std::istream& in, std::ostream& out)
    {
        float saveMaxNumber = 0.0f;
        float number;

        char nonNumberTrash;

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
                out << std::setfill(' ') << std::setw(5) <<  "" << std::setw(12) << std::internal  << std::showpoint << std::showpos << number << std::endl;
                continue;
            }
        }

        out << "max : " << std::setw(12) << std::internal << std::showpoint << std::showpos << saveMaxNumber << std::endl;
    }
}