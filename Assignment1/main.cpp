#include <cassert>
#include "MyString.h"

int main()
{
	assignment1::MyString myString("Pope");

	assert(myString.GetLength() == 4);

	myString.Append("HelloBro");
}