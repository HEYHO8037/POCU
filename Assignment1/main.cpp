#include <cassert>
#include "MyString.h"

int main()
{
	int a;
	assignment1::MyString myString("Pope");

	assignment1::MyString ms(myString);

	assignment1::MyString ab = myString + "";

	assert(myString.GetLength() == 4);

	ms.Append("");
	a = myString.IndexOf("o");
}