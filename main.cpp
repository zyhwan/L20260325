//Standard Template Library
#include <iostream>
#include <vector>
#include <array>
#include <list>

int main()
{
	std::vector<int> IntDArray;
	std::array<int, 5> IntArray{ 0, };

	IntDArray.push_back(1);
	IntDArray.push_back(2);
	IntDArray.push_back(3);
	IntDArray.push_back(4);
	IntDArray.push_back(5);

	for (int i = 0; i < IntDArray.size(); ++i)
	{
		std::cout << IntDArray[i] << std::endl;
		std::cout << IntArray[i] << std::endl;
	}
	
	std::list<int> IntList;

	IntList.push_back(1);
	IntList.push_back(2);
	IntList.push_back(3);
	IntList.push_back(4);

	//iterator, 반복자 <- 포인터
	IntList.begin();
	IntList.end();

	for (std::list<int>::iterator i = IntList.begin(); i != IntList.end(); ++i)
	{
		std::cout << *i << std::endl;
	}

	for (auto i : IntList) //auto로 i의 자료형을 컴파일 단계에서 정해준다. 
	{
		std::cout << i << std::endl;
	}



}