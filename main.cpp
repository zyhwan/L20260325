//Standard Template Library
#include <iostream>
#include <vector>
#include "DynamicArray.h"

using namespace std;


class FVector2D
{
public:
	FVector2D(int x = 0, int y = 0) : x(x), y(y)
	{

	}
	~FVector2D()
	{

	}

	const FVector2D& operator+(FVector2D& rhs)
	{
		FVector2D NewVector2D(*this);
		NewVector2D.x = x + rhs.x;
		NewVector2D.y = y + rhs.y;

		return NewVector2D;
	}


public:
	int x;
	int y;
};



int main()
{
	//FVector2D v1(1, 1);
	//FVector2D v2(2, 2);
	//FVector2D v3(v1 + v2);

	//v1 = v2 + v3;

	//cout << v1.x << ", " << v1.y << endl;
	//cout << v3.x << ", " << v3.y << endl;
	

	DynamicArray<int> V;

	V.Push_Back(1);
	V.Push_Back(3);
	V.Push_Back(2);
	V.Push_Back(4);
	V.Push_Back(5);

	for (DynamicArray<int>::Iterator iter = V.begin(); iter.operator!=(V.end()); iter++)
	{
		cout << *iter << endl;
	}

	//범위 기반 반복문을 사용하기 위해서는 begin, end 반복자가 필요하다. 그래서 메서드의 이름을 대문자로 만들지 않고 기준에 맞춰서 만들어줘야한다.
	for (auto i : V)
	{
		cout << i << endl;
	}

	return 0;
}