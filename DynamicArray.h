#pragma once
//만약 한번 include 했다면 더 안하게 하는 것.
#ifndef __DynamicArray_H__
#define __DynamicArray_H__
#include<stdexcept>

template<typename T>
class DynamicArray
{
public:
	DynamicArray() : Data(new T[1]), Size(0), Capacity(1)
	{

	}
	DynamicArray(int InitCapacity) : Data(new T[InitCapacity]),
		Size(0), Capacity(InitCapacity)
	{

	}
	~DynamicArray()
	{
		delete[] Data;
		Data = nullptr;
	}
	void ReSize()
	{
		if (Capacity == 0)
		{
			Capacity = 1;
		}
		else
		{
			if (Size >= Capacity) //만약에 용량을 넘어서면
			{
				Capacity *= 2;
				T* NewData = new T[Capacity];
				for (int i = 0; i < Size - 1; ++i)
				{
					NewData[i] = Data[i];
				}
				delete[] Data;
				Data = NewData;
			}
		}
	}
	void Push_Back(const T& InValue) //값 복사X, 원본 참조O
	{
		Size++;
		ReSize();
		Data[Size - 1] = InValue;
	}

	void erase(const int IDX)
	{
		if (IDX >= Size || Size < 0)
		{
			throw std::out_of_range("인덱스가 범위를 범어남.");
		}
		if (IDX < Size)
		{
			for (int i = IDX; i < Size; ++i)
			{
				Data[i] = Data[i + 1];
			}
			Size--;
		}
	}

	inline size_t GetSize() const //멤버 함수 뒤에 붙은 const는 본인 멤버 변수의 변경을 막겠는다는 의미. (읽기 전용)
	{
		return Size;
	}
	inline size_t GetCapacity() const //멤버 함수 뒤에 붙은 const는 본인 멤버 변수의 변경을 막겠는다는 의미. (읽기 전용)
	{
		return Capacity;
	}
	//원본 데이터를 복사하는 것은 비용이 너무 크다. 그래서 C++에서는 &래퍼런스 참조를 지원해줘서 원본데이터의 주소를 넘길 수 있다.
	//&로 리턴해주기 때문에 이 객체의 Data의 주소를 넘겨준다. 그래서 '변수[0] = 데이터 값' 이런식으로 참조할 수 있다.
	//하지만 const를 int& 앞에 붙여주면 리턴값 변경이 불가하기 때문에 외부에서 반환값을 바꾸지 못한다.
	const T& operator[](int Index) const
	{
		if (Index > Size)
		{
			//throw std::out_of_range("인덱스가 범위를 범어남");
			throw std::exception("인덱스가 범위를 범어남");
		}
		return Data[Index];
	}

	void clear()
	{
		Size = 0;
	}

protected:
	T* Data;
	size_t Size; //size_t <- 컴파일러의 비트수에 따라 데이터의 크기가 다르기 때문에 이를 맞춰주기 위해 이미 정의된 int형 자료형이다.
	size_t Capacity;

public:
	//반복자 만들기.--------------------------------------------------------------------
	class Iterator
	{
	public:
		Iterator(T* InPointer) : Pointer(InPointer)
		{

		}
		~Iterator()
		{

		}
		//전위 증가
		Iterator operator++()
		{
			Pointer++;
			return *this;
		}
		//후위 증가
		Iterator operator++(int)
		{
			Pointer++;
			return Iterator(Pointer);
		}
		inline bool operator!=(const Iterator& Other)
		{
			return Pointer != Other.Pointer;
		}
		T& operator*()
		{
			return *Pointer;
		}
	protected:
		T* Pointer;
	};
	//--------------------------------------------------------------------
public:
	Iterator begin()
	{
		return Iterator(Data);
	}
	Iterator end()
	{
		return Iterator(Data + Size);
	}


};

#endif //__DynamicArray_H__