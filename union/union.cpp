#include <iostream>
using namespace std;

union mix_t {
	int a;
	struct {
		short hi;
		short lo;
	} s;
	char c[4];
} mix;

int main(){
	cout << "Enter value for int a \n";
	cin >> mix.a;
	
	cout << "The value for a is " << mix.a << endl;
	cout << "Enter value for short hi \n";
	cin >> mix.s.hi;
	
	cout << "The value for short hi " << mix.s.hi << endl;
	cout << "Enter value for short lo \n";
	cin >> mix.s.lo;
	
	cout << "The value for short lo " << mix.s.lo << endl;
	cout << "The value for a is " << mix.a << endl;
	
	cout << "The value for c[0] is " << mix.c[0] << endl;
	cout << "The value for c[1] is " << mix.c[1] << endl;
	cout << "The value for c[2] is " << mix.c[2] << endl;
	cout << "The value for c[3] is " << mix.c[3] << endl;

	return 0;
}
