#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
	{
		int otherLength;
		int length;

		if (s == nullptr)
		{
			mStringLength = 0;
		}
		else
		{
			for (otherLength = 0; s[otherLength]; otherLength++);

			mStringLength = otherLength + 2;

			mString = new char[mStringLength];

			for (length = 0; length <= otherLength; length++)
			{
				mString[length] = s[length];
			}

			mString[mStringLength - 1] = '\0';
		}

	}

	MyString::MyString(const MyString& other)
	{
		int otherLength;
		int length;
		const char* getString = other.GetCString();
		int isEmpty;

		if (getString != nullptr)
		{
			isEmpty = *other.GetCString();

			for (otherLength = 0; getString[otherLength]; otherLength++);

			mStringLength = otherLength + 2;

			mString = new char[mStringLength];

			for (length = 0; length <= otherLength; length++)
			{
				mString[length] = getString[length];
			}

			mString[mStringLength - 1] = '\0';
		}
	}

	MyString::~MyString()
	{
		delete[] mString;
	}

	unsigned int MyString::GetLength() const
	{
		int length = 0;

		if (mString != nullptr)
		{
			for (length = 0; mString[length]; length++);
		}
		else
		{
			return 0;
		}

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
		int length = 0;
		int getNum = 0;
		char* appendString;
		int isEmpty;
		int secondLength;


		if (s != nullptr)
		{
			isEmpty = *s;

			if (isEmpty != 0)
			{
				for (otherLength = 0; s[otherLength]; otherLength++);

				mStringLength = GetLength() + otherLength + 2;

				appendString = new char[mStringLength];

				if (mString != nullptr)
				{
					for (length = 0; mString[length]; length++)
					{
						appendString[length] = mString[length];
					}
				}

				secondLength = mStringLength - 1;

				for (; length < secondLength; length++)
				{
					appendString[length] = s[getNum];
					getNum++;
				}

				appendString[mStringLength - 1] = '\0';

				delete[] mString;

				mString = appendString;

				appendString = nullptr;
			}
		}
	}

	MyString MyString::operator+(const MyString& other) const
	{
		const char* saveString = GetCString();

		MyString plusString(saveString);
		plusString.Append(other.GetCString());

		return plusString;
	}

	int MyString::IndexOf(const char* s)
	{
		if (s == nullptr)
		{
			return -1;
		}
		else
		{
			int index = -1;
			int isEqual = 0;
			int isEmpty = *s;
			int length;

			if (isEmpty == 0)
			{
				return 0;
			}

			for (length = 0; s[length]; length++);

			for (int totalNum = 0; mString[totalNum]; totalNum++)
			{
				isEqual = 0;

				for (int subNum = 0; s[subNum]; subNum++)
				{
					if (mString[totalNum + subNum] == s[subNum])
					{
						isEqual++;
					}
					else
					{
						continue;
					}
				}

				if (isEqual == length)
				{
					index = totalNum;
					break;
				}
			}

			return index;
		}
	}

	int MyString::LastIndexOf(const char* s)
	{
		if (s == nullptr)
		{
			return -1;
		}
		else
		{
			int index = -1;
			int isEqual = 0;
			int isEmpty = *s;
			int length;

			if (isEmpty == 0)
			{
				return GetLength();
			}

			for (length = 0; s[length]; length++);

			for (int totalNum = 0; mString[totalNum]; totalNum++)
			{
				isEqual = 0;

				for (int subNum = 0; s[subNum]; subNum++)
				{
					if (mString[totalNum + subNum] == s[subNum])
					{
						isEqual++;
					}
					else
					{
						continue;
					}
				}

				if (isEqual == length)
				{
					index = totalNum;
				}
			}

			return index;
		}
	}

	void MyString::Interleave(const char* s)
	{
		int otherLength;
		int saveLength;
		int length;
		int isEmpty;
		int myLength = GetLength();

		char* saveString;
		char* storeString;

		int firstNum = 0;
		int secondNum = 0;

		if (s != nullptr)
		{
			isEmpty = *s;

			if (isEmpty != 0)
			{
				for (otherLength = 0; s[otherLength]; otherLength++);

				saveLength = otherLength + myLength;

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
				else if (otherLength != saveLength && otherLength != 0)
				{
					mStringLength += otherLength;

					saveString = new char[mStringLength];

					for (length = 0; length < mStringLength - 1; length++)
					{
						if (length % 2 == 0 && firstNum < myLength)
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
							if (firstNum < myLength)
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
		}
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		char* saveString;
		char* storeString;
		int myRemovePosition = i;
		int length = 0;
		int saveNum = 0;
		int saveLength = mStringLength - 2;

		if (saveLength <= myRemovePosition)
		{
			return false;
		}
		else
		{
			mStringLength -= 1;
			saveString = new char[mStringLength];

			for (length = 0; length <= saveLength; length++)
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
		char* saveString;
		char* storeString;
		int length;
		int padNum = totalLength - GetLength();

		if (totalLength > GetLength())
		{
			mStringLength = totalLength + 1;
			saveString = new  char[mStringLength];

			for (length = 0; length < mStringLength - 1; length++)
			{
				if (length < padNum)
				{
					saveString[length] = ' ';
				}
				else
				{
					saveString[length] = mString[length - padNum];
				}
			}

			saveString[mStringLength - 1] = '\0';

			storeString = mString;
			mString = saveString;
			saveString = nullptr;
			delete[] storeString;
		}

	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		char* saveString;
		char* storeString;
		int length;
		int padNum = totalLength - GetLength();

		if (totalLength > GetLength())
		{
			mStringLength = totalLength + 1;
			saveString = new  char[mStringLength];

			for (length = 0; length < mStringLength - 1; length++)
			{
				if (length < padNum)
				{
					saveString[length] = c;
				}
				else
				{
					saveString[length] = mString[length - padNum];
				}
			}

			saveString[mStringLength - 1] = '\0';

			storeString = mString;
			mString = saveString;
			saveString = nullptr;
			delete[] storeString;
		}

	}

	void MyString::PadRight(unsigned int totalLength)
	{
		char* saveString;
		char* storeString;

		int myPadLength = totalLength;
		int myLength = GetLength();
		int length;
		int padNum = myPadLength - myLength;

		if (myPadLength > myLength)
		{
			mStringLength = myPadLength + 1;
			saveString = new  char[mStringLength];

			for (length = 0; length < mStringLength - 1; length++)
			{
				if (length < myLength)
				{
					saveString[length] = mString[length];
				}
				else
				{
					saveString[length] = ' ';
				}
			}

			saveString[mStringLength - 1] = '\0';

			storeString = mString;
			mString = saveString;
			saveString = nullptr;
			delete[] storeString;
		}
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		char* saveString;
		char* storeString;

		int myPadLength = totalLength;
		int myLength = GetLength();
		int length;
		int padNum = myPadLength - myLength;

		if (myPadLength > myLength)
		{
			mStringLength = myPadLength + 1;
			saveString = new  char[mStringLength];

			for (length = 0; length < mStringLength - 1; length++)
			{
				if (length < myLength)
				{
					saveString[length] = mString[length];
				}
				else
				{
					saveString[length] = c;
				}
			}

			saveString[mStringLength - 1] = '\0';

			storeString = mString;
			mString = saveString;
			saveString = nullptr;
			delete[] storeString;
		}
	}

	void MyString::Reverse()
	{
		int length;
		char save;
		int maxLength = GetLength() / 2;

		if (maxLength != 0 && mString != nullptr)
		{
			for (length = 0; length < maxLength; length++)
			{
				save = mString[length];
				mString[length] = mString[GetLength() - length - 1];
				mString[GetLength() - length - 1] = save;
			}
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		char* firstString = mString;
		char* secondString = rhs.mString;

		bool bCompare = false;

		int firstLength = GetLength();
		int secondLength = rhs.GetLength();
		int length;


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

	MyString& MyString::operator=(const MyString& rhs)
	{
		mStringLength = rhs.mStringLength;

		int length;
		int otherLength = rhs.GetLength();

		char* saveString = new char[mStringLength];
		char* storeString;
		char* otherString = rhs.mString;

		for (length = 0; length <= otherLength; length++)
		{
			saveString[length] = otherString[length];
		}

		saveString[mStringLength - 1] = '\0';

		storeString = mString;
		mString = saveString;

		saveString = nullptr;
		delete[] storeString;


		return *this;
	}

	void MyString::ToLower()
	{
		int length;
		int myLength = GetLength();

		for (length = 0; length <= myLength; length++)
		{
			if (mString[length] > 64 && mString[length] < 91)
			{
				mString[length] += 32;
			}
			else
			{
				continue;
			}
		}
	}

	void MyString::ToUpper()
	{
		int length;
		int myLength = GetLength();

		for (length = 0; length <= myLength; length++)
		{
			if (mString[length] > 96 && mString[length] < 123)
			{
				mString[length] -= 32;
			}
			else
			{
				continue;
			}
		}
	}
}