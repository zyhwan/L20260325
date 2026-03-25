#pragma once
//만약 한번 include 했다면 더 안하게 하는 것.
#ifndef __DynamicArray_H__
#define __DynamicArray_H__

class DynamicArray
{
public:
	DynamicArray() : Data(nullptr), Size(0), Capacity(1)
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
				int* NewData = new int[Capacity];
				for (int i = 0; i < Size - 1; ++i)
				{
					NewData[i] = Data[i];
				}
				delete[] Data;
				Data = NewData;
			}
		}
	}
	void Push_Back(const int InValue)
	{
		Size++;
		ReSize();
		Data[Size - 1] = InValue;
	}

	void erase(const int IDX)
	{
		if (IDX < Size)
		{
			for (int i = IDX; i < Size; ++i)
			{
				Data[i] = Data[i + 1];
			}
			Size--;
		}
	}

	//void Push_Back(const int InValue)
	//{
	//	Size++; //Push_back()을 한다면 크기를 한개씩 늘린다.
	//	if (Size > Capacity) //만약 수용량보다 Size가 커진다면
	//	{
	//		Capacity *= 2; //Capacity 크기를 2배씩 늘린다.

	//		//1. 늘어난 영역 만큼 새로 할당.
	//		int* NewData = new int[Capacity];

	//		//2. 원본 복제
	//		for (int i = 0; i < Size - 1; ++i)
	//		{
	//			NewData[i] = Data[i];
	//		}

	//		//3. 새로들어온 값을 넣는다.
	//		NewData[Size - 1] = InValue;

	//		//4. 원래 있는걸 지운다.
	//		delete[] Data;

	//		//5. 원래 데이터의 포인터에 새 데이터 포인터 연결
	//		Data = NewData;
	//	}
	//	else //수용량 보다 작거나 같다면
	//	{
	//		if (Size == 1) //처음에만 하나 할당.
	//		{
	//			//1. 늘어난 영역 만큼 새로 할당.
	//			int* NewData = new int[Size];

	//			//2. 원본 복제
	//			for (int i = 0; i < Size - 1; ++i)
	//			{
	//				NewData[i] = Data[i];
	//			}

	//			//3. 새로들어온 값을 넣는다.
	//			NewData[Size - 1] = InValue;

	//			//4. 원래 있는걸 지운다.
	//			delete[] Data;

	//			//5. 원래 데이터의 포인터에 새 데이터 포인터 연결
	//			Data = NewData;

	//			return;
	//		}
	//		Data[Size - 1] = InValue; //수용량을 넘지 않았다면 원래 할당한 메모리 영역에 데이터 넣기.
	//	}
	//}

	inline size_t GetSize() const //멤버 함수 뒤에 붙은 const는 본인 멤버 변수의 변경을 막겠는다는 의미. (읽기 전용)
	{
		return Size;
	}

	//원본 데이터를 복사하는 것은 비용이 너무 크다. 그래서 C++에서는 &래퍼런스 참조를 지원해줘서 원본데이터의 주소를 넘길 수 있다.
	//&로 리턴해주기 때문에 이 객체의 Data의 주소를 넘겨준다. 그래서 '변수[0] = 데이터 값' 이런식으로 참조할 수 있다.
	//하지만 const를 int& 앞에 붙여주면 리턴값 변경이 불가하기 때문에 외부에서 반환값을 바꾸지 못한다.
	const int& operator[](int Index) const
	{
		return Data[Index];
	}


//protected:
	int* Data;
	size_t Size; //size_t <- 컴파일러의 비트수에 따라 데이터의 크기가 다르기 때문에 이를 맞춰주기 위해 이미 정의된 int형 자료형이다.
	size_t Capacity;
};

#endif //__DynamicArray_H__