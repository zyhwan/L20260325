#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

class String
{
public:
	String() : STR(nullptr), length(0)
	{

	}
	~String()
	{
		std::cout << "소멸자 호출" << std::endl;
		if (STR != nullptr)
		{
			delete[] STR;
			STR = nullptr;
		}
	}

	//기본 생성자
	String(const char* str)
	{
		length = GetLength(str);
		Alloc();
		Copy(str);
	}

	//복사 생성자
	String(const String& rhs) //읽기 전용으로 다른 객체를 가져옴.
	{
		length = rhs.length;
		Alloc();
		Copy(rhs);
	}

	// =연산자 오버로딩
	String& operator=(const char* rhs)
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
	String& operator=(const String& rhs)
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

	//+연산자 오버로딩
	const char* operator+(const char* other)
	{
		int len = length + GetLength(other);
		int OtherLength = GetLength(other);
		char* TempString = new char[len + 1];
		
		for (int i = 0; i < length; ++i)
		{
			TempString[i] = STR[i];
		}
		for (int i = 0; i < OtherLength; ++i)
		{
			TempString[i + length] = other[i];
		}
		TempString[len] = '\0';

		return TempString;
	}

	String operator+(const String& other)
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

	//문자열 받기
	char* GetStr() const
	{
		return STR;
	}

	int GetLen()
	{
		return length;
	}

	//메모리 확보하기
	void Alloc()
	{
		STR = new char[length + 1];
	}

	//복사하기 문자로 받을 때
	void Copy(const char* rhs)
	{
		for (int i = 0; i < length; ++i)
		{
			STR[i] = rhs[i];
		}
		STR[length] = '\0';
	}

	//복사하기 String 클래스로 받을 때
	void Copy(const String& rhs)
	{
		for (int i = 0; i < length; ++i)
		{
			STR[i] = rhs.STR[i];
		}
		STR[length] = '\0';
	}

	//문자열 넣으면 길이 반환
	int GetLength(const char* rhs) const
	{
		int len = 0;
		for (int i = 0; rhs[i] != '\0'; ++i)
		{
			++len;
		}
		return len;
	}
	int GetLength(const String& rhs) const
	{
		int len = 0;
		for (int i = 0; rhs.STR[i] != '\0'; ++i)
		{
			++len;
		}
		return len;
	}
private:
	char* STR; //문자 포인터
	int length;//문자열 길이
};

