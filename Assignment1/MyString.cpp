#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
	{
		int otherLength;
		int length;

		for (otherLength = 0; s[otherLength]; otherLength++);

		mStringLength = otherLength + 2;

		mString = new char[mStringLength];

		for (length = 0; length <= otherLength; length++)
		{
			mString[length] = s[length];
		}

		mString[mStringLength-1] = '\0';

	}

	MyString::MyString(const MyString& other)
	{
		int otherLength;
		int length;
		const char* getString = other.GetCString();

		for (otherLength = 0; getString[otherLength]; otherLength++);

		mStringLength = otherLength + 2;

		mString = new char[mStringLength];

		for (length = 0; length <= otherLength; length++)
		{
			mString[length] = getString[length];
		}

		mString[mStringLength - 1] = '\0';
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
		const char* cString = mString;

		return cString;
	}

	void MyString::Append(const char* s)
	{
		int otherLength;
		int length;
		int getNum = 0;
		char* appendString;

		for (otherLength = 0; s[otherLength]; otherLength++);

		mStringLength = GetLength() + otherLength + 2;

		appendString = new char[mStringLength];

		for (length = 0; mString[length]; length++)
		{
			appendString[length] = mString[length];
		}

		for (; length <= mStringLength - 2; length++)
		{
			appendString[length] = s[getNum];
			getNum++;
		}

		appendString[mStringLength - 1] = '\0';

		delete[] mString;

		mString = appendString;

		appendString = nullptr;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		MyString PlusString(GetCString());
		PlusString.Append(other.GetCString());

		return PlusString;
	}

	int MyString::IndexOf(const char* s)
	{
		int index = -1;
		bool bEqual = false;
		
		for (int totalNum = 0; mString[totalNum]; totalNum++)
		{
			for (int subNum = 0; s[subNum]; subNum++)
			{
				if (mString[totalNum + subNum] == s[subNum])
				{
					bEqual = true;
				}
				else
				{
					bEqual = false;
				}
			}

			if (bEqual)
			{
				index = totalNum;
			}
		}

		return index;
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