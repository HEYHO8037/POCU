#include <cassert>
#include "MyString.h"

int main()
{
	int a;
	int b;
	bool c;
	assignment1::MyString myString("abc");

	assignment1::MyString ms("cde");

	c = ms == myString;

	assignment1::MyString ab = myString + "";

	assert(myString.GetLength() == 4);

	ms.Append("");
	a = myString.IndexOf("");
	b = myString.LastIndexOf("p");
}