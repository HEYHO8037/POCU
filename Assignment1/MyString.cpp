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

		mStringLength += otherLength;

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
				break;
			}
		}

		return index;
	}

	int MyString::LastIndexOf(const char* s)
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

	void MyString::Interleave(const char* s)
	{
		int otherLength;
		int saveLength;
		int length;

		char* saveString;
		char* storeString;

		int firstNum = 0;
		int secondNum = 0;

		for (otherLength = 0; s[otherLength]; otherLength++);

		saveLength = otherLength + GetLength();

		if (otherLength == saveLength)
		{
			delete[] mString;

			mStringLength = otherLength + 2;

			mString = new char[mStringLength];

			for (length = 0; length <= otherLength; length++)
			{
				mString[length] = s[length];
			}

			mString[mStringLength - 1] = '\0';
		}
		else if(otherLength != saveLength && otherLength != 0)
		{
			mStringLength += otherLength;

			saveString = new char[mStringLength];

			for (length = 0; length < mStringLength-1; length++)
			{
				if (length % 2 == 0 && firstNum < GetLength())
				{
					saveString[length] = mString[firstNum];
					firstNum++;
				}
				else if (length % 2 != 0 && secondNum < otherLength)
				{
					saveString[length] = s[secondNum];
					secondNum++;
				}
				else
				{
					if (firstNum < GetLength())
					{
						saveString[length] = mString[firstNum];
						firstNum++;
					}
					else
					{
						saveString[length] = s[secondNum];
						secondNum++;
					}
				}
			}

			saveString[mStringLength - 1] = '\0';

			storeString = mString;
			mString = saveString;

			saveString = nullptr;
			delete[] storeString;

		}
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		char* saveString;
		char* storeString;
		int length = 0;
		int saveNum = 0;
		int saveLength = mStringLength;


		mStringLength -= 1;
		if (saveLength - 2 <= i)
		{
			return false;
		}
		else
		{
			saveString = new char[mStringLength];

			for (length = 0; length < saveLength - 1; length++)
			{
				if (length == i)
				{
					continue;
				}
				else
				{
					saveString[saveNum] = mString[length];
					saveNum++;
				}
			}

			saveString[mStringLength - 1] = '\0';

			storeString = mString;
			mString = saveString;

			saveString = nullptr;
			delete[] storeString;
			
			return true;
		}
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
		MyString Compare(GetCString());

		char* firstString = Compare.mString;
		char* secondString = rhs.mString;

		bool bCompare = false;

		int firstLength = Compare.GetLength();
		int secondLength = rhs.GetLength();
		int length;

		if (firstLength != secondLength)
		{
			return false;
		}
		else
		{
			for (length = 0; length <= firstLength; length++)
			{
				if (firstString[length] == secondString[length])
				{
					bCompare = true;
				}
				else
				{
					bCompare = false;
					break;
				}
			}

			if (bCompare)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
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