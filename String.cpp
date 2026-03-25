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
	int OtherLength = GetLength(other);
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