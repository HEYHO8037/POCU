#include <iostream>

#include "TimeSheet.h"

int main()
{

	lab3::TimeSheet employee2("Pope", 10);
	employee2.AddTime(4);    // ok

	std::cout << employee2.GetTotalTime() << std::endl;          // 17
	std::cout << employee2.GetAverageTime() << std::endl;        // 5.66667

	lab3::TimeSheet pope(employee2);

	pope.AddTime(5);    // ok
	pope.AddTime(1);    // ok
	pope.AddTime(2);    // ok

	std::cout << pope.GetTotalTime() << std::endl;          // 25
	std::cout << pope.GetAverageTime() << std::endl;        // 4.16667
	std::cout << pope.GetStandardDeviation() << std::endl;  // 2.11476(모집단의 표준편차)
	std::cout << pope.GetName() << std::endl;               // Pope

	lab3::TimeSheet hulk("HULK", 10);
	std::cout << hulk.GetStandardDeviation() << std::endl;//0.0
}