#include <iostream>
using namespace std;

main()
{
	double a = 10.2;
	float b = 5.09;
	int c;
	
	c = (int)a;
	cout << "(int) a :" << c << endl;
	
	c = (int)b;
	cout << "(int) b :" << c << endl;
	
	int e, d;
	e = (d = 4, d + 7);
	cout << "c = (d = 4, d + 7):" << e << endl;
	
	int x;
	int y = 10;
	int z = 5;
	
	x = (y < z) ? y - z : z - y;
	cout << "(y < z) ? y - z : z - y :" << x << endl;
	
	return 0;
}