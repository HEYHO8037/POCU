#include "Lab2.h"

namespace lab2
{
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
        int number;
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
                out << std::setfill(' ') << std::setw(12) << std::oct << number;
                out << std::setfill(' ') << std::setw(12) << std::dec << number;
                out << std::setfill(' ') << std::setw(12) << std::hex << number << std::endl;
                continue;
            }
        }
    }

    void PrintMaxFloat(std::istream& in, std::ostream& out)
    {
        float saveMaxNumber = 0;
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
                out << std::setfill(' ') << std::setw(5) <<  "" << std::setw(12) << std::internal << number << std::endl;
                continue;
            }
        }

        out << "max : " << std::setw(12) << std::internal << saveMaxNumber << std::endl;
    }
}