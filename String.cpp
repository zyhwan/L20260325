#include "String.h"


String& String::operator=(const char* rhs)
{
	length = GetLength(rhs);
	if (STR != nullptr)
	{
		delete[] STR;
	}
	Alloc();
	Copy(rhs);
	return *this;
}

String& String::operator=(const String& rhs)
{
	length = rhs.length;
	if (STR != nullptr)
	{
		delete[] STR;
	}
	Alloc();
	Copy(rhs);
	return *this;
}

const char* String::operator+(const char* other)
{
	int Totallength = length + GetLength(other);
	int OtherLength = GetLength(other);
	char* TempString = new char[Totallength + 1];

	for (int i = 0; i < length; ++i)
	{
		TempString[i] = STR[i];
	}
	for (int i = 0; i < OtherLength; ++i)
	{
		TempString[i + length] = other[i];
	}
	TempString[Totallength] = '\0';

	return TempString;
}


String String::operator+(const String& other)
{
	String TempString;
	size_t OtherLength = GetLength(other);
	TempString.length = length + OtherLength;
	TempString.Alloc();

	for (int i = 0; i < length; ++i)
	{
		TempString.STR[i] = STR[i];
	}
	for (int i = 0; i < OtherLength; ++i)
	{
		TempString.STR[i + length] = other.STR[i];
	}

	TempString.STR[TempString.length] = '\0';

	return TempString;
}

const char& String::operator[](int Index) const
{
	if (Index < 0 || Index > length)
	{
		throw std::exception("ÀÎµ¦½º ¹üÀ§¸¦ ¹þ¾î³²");
	}
	return STR[Index];
}

String& String::operator+=(const char* other)
{
	String temp(*this); //ÀÓ½Ã °´Ã¼
	length = length + GetLength(other);

	if (STR != nullptr)
	{
		delete[] STR;
	}

	STR = new char[length + 1];

	for (int i = 0; i < temp.length; ++i)
	{
		STR[i] = temp.STR[i];
	}

	for (int i = 0; i < GetLength(other); ++i)
	{
		STR[i + temp.length] = other[i];
	}

	STR[length] = '\0';

	return *this;
}
