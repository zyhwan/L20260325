//Standard Template Library
#include <iostream>
#include <vector>
#include "DynamicArray.h"

using namespace std;


int main()
{
	DynamicArray OurArray;

	vector<int> v;

	v.resize(5);

	OurArray.Push_Back(1);
	OurArray.Push_Back(2);
	OurArray.Push_Back(3);
	OurArray.Push_Back(4);
	OurArray.Push_Back(5);
	OurArray.Push_Back(6);
	OurArray.Push_Back(7);
	OurArray.Push_Back(8);
	OurArray.Push_Back(9);
	OurArray.Push_Back(10);
	OurArray.Push_Back(11);
	OurArray.Push_Back(12);
	OurArray.Push_Back(13);
	OurArray.Push_Back(14);
	OurArray.Push_Back(15);


	for (int i = 0; i < OurArray.GetSize(); ++i)
	{
		//cout << OurArray.Data[i] << endl;
		cout << OurArray[i] << endl; //OurArray.operator[](i)와 같은 의미.
	}

	OurArray.erase(1);

	for (int i = 0; i < OurArray.GetSize(); ++i)
	{
		//cout << OurArray.Data[i] << endl;
		cout << OurArray[i] << endl; //OurArray.operator[](i)와 같은 의미.
	}


	cout << "수용량: " << OurArray.Capacity << endl;

	return 0;
}