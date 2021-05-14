#include <cassert>
#include "MyString.h"

int main()
{
	assignment1::MyString my1("abc");
	assignment1::MyString my2("");
	assignment1::MyString m3 = my1 + my2;

	my1.PadRight(6);



	return 0;
}