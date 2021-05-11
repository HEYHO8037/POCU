#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
	{
		int length;
		int num;
		char a;

		for (length = 0; s[length]; length++);

		mString = new char[length + 1];

		for (num = 0; num <= length; num++)
		{
			mString[num] = s[num];
		}
	}

	MyString::MyString(const MyString& other)
	{

	}

	MyString::~MyString()
	{
		delete[] mString;
	}

	unsigned int MyString::GetLength() const
	{
		int length;

		for (length = 0; mString[length]; length++);

		return length;
	}

	const char* MyString::GetCString() const
	{
		const char* pString = mString;
		return pString;
	}

	void MyString::Append(const char* s)
	{
		int length;
		int num;
		int totalLength;
		int getNum = 0;

		for (length = 0; s[length]; length++);

		totalLength = GetLength() + length + 1;

		char* appendString = new char[totalLength];

		for (num = 0; num <= GetLength(); num++)
		{
			appendString[num] = mString[num];
		}

		for (num = GetLength(); num <= totalLength - 1; num++)
		{
			appendString[num] = s[getNum];
			getNum++;
		}

		delete[] mString;

		mString = appendString;

		appendString = nullptr;
	}

	MyString MyString::operator+(const MyString& other) const
	{






		return MyString("ABC");
	}

	int MyString::IndexOf(const char* s)
	{
		return 0;
	}

	int MyString::LastIndexOf(const char* s)
	{
		return 0;
	}

	void MyString::Interleave(const char* s)
	{
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		return false;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
	}

	void MyString::PadRight(unsigned int totalLength)
	{
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
	}

	void MyString::Reverse()
	{
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		return false;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		return *this;
	}

	void MyString::ToLower()
	{
	}

	void MyString::ToUpper()
	{
	}
}