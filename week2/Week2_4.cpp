#include <iostream>
using namespace std;

int main()
{
	int var = 10;
	int * ptr;
	int val;
		ptr = &var; //Take address of var
		val = *ptr; // Take the value available at ptr
		
	cout << "Value of var :" << var << endl;
	cout << "Value of ptr :" << ptr << endl;
	cout << "Value of var :" << var << endl;
	
	return 0;
}