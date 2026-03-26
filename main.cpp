//Standard Template Library
#include <iostream>
#include <vector>
#include "DynamicArray.h"
#include "String.h"

using namespace std;


int main()
{
	String s1("Hello");
	String s2("Hello2");
	String s3(s1);
	String s4;

	s1 = s2 + "abc";
	s4 = s1 + s2;

	s4 += "ddd";

	cout << s1.GetStr() << endl;
	cout << s2.GetStr() << endl;
	cout << s3.GetStr() << endl;
	cout << s4.GetStr() << endl;
	cout << s4[1] << endl;

	return 0;
}