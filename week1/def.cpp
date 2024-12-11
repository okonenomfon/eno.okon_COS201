#include <iostream>
using namespace std;
typedef char C;
typedef int N;
typedef char field [50];

int main () {
	C x = 'a';
	N y = 10;
	N z = 5;
	field characters = "Hello World";
	
	N c = y + z;
	
	cout << "N c = y + z so c = " << c << endl;
	cout << "field characters = " << characters << endl;
	cout << "C x = 'a', so x = " << x << endl;
	
	return 0;
}