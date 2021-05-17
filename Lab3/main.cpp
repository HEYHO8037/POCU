#include <iostream>

#include "TimeSheet.h"

int main()
{

	lab3::TimeSheet employee2("Pope", 10);
	lab3::TimeSheet employee1("abc", 2);
	employee2.AddTime(4);
	employee2.AddTime(10);
	employee2.AddTime(3);

	employee1 = employee2;
}