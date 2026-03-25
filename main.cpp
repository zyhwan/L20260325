//Standard Template Library
#include <iostream>
#include <vector>
#include "DynamicArray.h"

using namespace std;

int main()
{
	DynamicArray OurArray;

	try
	{
		OurArray.erase(10);
	}
	catch (std::out_of_range e)
	{
		cout << e.what() << endl;
	}
	

	return 0;
}